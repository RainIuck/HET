#!/usr/bin/env python3
from collections import deque
import math
import threading
import time

import rclpy
from alicia_d_control_interfaces.action import (
    ForceGrasp,
    HomeGripper,
    MoveGripper,
    MoveGripperStep,
)
from alicia_d_control_interfaces.msg import GripperState
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from sensor_msgs.msg import JointState

from alicia_d_sts_gripper.sts3215_bus import Sts3215Bus, Sts3215Error


class Sts3215GripperNode(Node):
    ENCODER_MODULUS = 4096

    def __init__(self):
        super().__init__("sts3215_gripper")
        self._declare_parameters()
        self._load_parameters()

        self._bus = None
        self._io_lock = threading.Lock()
        self._action_lock = threading.Lock()
        self._busy = False
        self._connected = False
        self._homed = False
        self._fault = ""
        self._last_state = None
        self._last_raw = 0
        self._zero_feedback_position = self.zero_feedback_position
        self._relative_ticks = 0
        self._homed = self.manual_home_valid

        self._joint_pub = self.create_publisher(JointState, "joint_states", 10)
        self._state_pub = self.create_publisher(GripperState, "state", 10)
        self._home_action = ActionServer(
            self,
            HomeGripper,
            "home",
            execute_callback=self._execute_home,
            goal_callback=self._goal_callback,
            cancel_callback=self._cancel_callback,
        )
        self._move_action = ActionServer(
            self,
            MoveGripper,
            "move_relative",
            execute_callback=self._execute_move,
            goal_callback=self._move_goal_callback,
            cancel_callback=self._cancel_callback,
        )
        self._move_step_action = ActionServer(
            self,
            MoveGripperStep,
            "move_step",
            execute_callback=self._execute_move_step,
            goal_callback=self._move_step_goal_callback,
            cancel_callback=self._cancel_callback,
        )
        self._force_action = ActionServer(
            self,
            ForceGrasp,
            "force_grasp",
            execute_callback=self._execute_force_grasp,
            goal_callback=self._force_goal_callback,
            cancel_callback=self._cancel_callback,
        )
        self._timer = self.create_timer(
            1.0 / max(0.1, self.state_publish_rate),
            self._publish_state,
        )

        if self.connect_on_start:
            try:
                with self._io_lock:
                    self._connect()
                    if self.torque_on_start:
                        self._bus.enable_torque(self.servo_id, True)
                self.get_logger().info(
                    f"Connected to STS3215 gripper id={self.servo_id} on {self.port}"
                )
            except Exception as exc:
                self._set_fault(f"Initial connection failed: {exc}")

        self.get_logger().info(
            "STS3215 gripper actions ready: 'home', 'move_relative', "
            "'move_step', 'force_grasp'. "
            f"home_raw={self.home_raw}, open_ticks={self.open_ticks}, "
            f"max_closed_ticks={self.max_closed_ticks}"
        )

    def _declare_parameters(self):
        self.declare_parameter("port", "/dev/ttyUSB0")
        self.declare_parameter("baudrate", 1000000)
        self.declare_parameter("servo_id", 1)
        self.declare_parameter("joint_name", "NewGripper")
        self.declare_parameter("home_raw", 0)
        self.declare_parameter("homing_speed", 300)
        self.declare_parameter("homing_acceleration", 10)
        self.declare_parameter("homing_timeout_s", 8.0)
        self.declare_parameter("torque_off_after_home", True)
        self.declare_parameter("manual_home_valid", False)
        self.declare_parameter("zero_feedback_position", 0)
        self.declare_parameter("zero_target_position", 0)
        self.declare_parameter("open_ticks", 0)
        self.declare_parameter("max_closed_ticks", 4700)
        self.declare_parameter("min_safe_ticks", 0)
        self.declare_parameter("max_safe_ticks", 4700)
        self.declare_parameter("max_step_command_ticks", 4700)
        self.declare_parameter("tick_tolerance", 20)
        self.declare_parameter("open_width_m", 0.08)
        self.declare_parameter("closed_width_m", 0.0)
        self.declare_parameter("default_speed", 500)
        self.declare_parameter("default_acceleration", 20)
        self.declare_parameter("force_grasp_speed", 200)
        self.declare_parameter("force_current_threshold_raw", 7)
        self.declare_parameter("force_load_threshold_raw", 1100)
        self.declare_parameter("force_contact_confirm_samples", 8)
        self.declare_parameter("force_require_slowdown", True)
        self.declare_parameter("force_slow_window_samples", 6)
        self.declare_parameter("force_slow_max_delta_ticks", 25)
        self.declare_parameter("force_min_valid_voltage_v", 1.0)
        self.declare_parameter("force_min_valid_temperature_c", 1)
        self.declare_parameter("force_max_load_jump_raw", 500)
        self.declare_parameter("force_max_current_jump_raw", 500)
        self.declare_parameter("move_time", 0)
        self.declare_parameter("raw_tolerance", 12)
        self.declare_parameter("goal_timeout_s", 8.0)
        self.declare_parameter("poll_period_s", 0.05)
        self.declare_parameter("serial_timeout_s", 0.12)
        self.declare_parameter("serial_write_timeout_s", 1.0)
        self.declare_parameter("state_publish_rate", 10.0)
        self.declare_parameter("connect_on_start", True)
        self.declare_parameter("torque_on_start", True)

    def _load_parameters(self):
        self.port = str(self.get_parameter("port").value)
        self.baudrate = int(self.get_parameter("baudrate").value)
        self.servo_id = int(self.get_parameter("servo_id").value)
        self.joint_name = str(self.get_parameter("joint_name").value)
        self.home_raw = int(self.get_parameter("home_raw").value)
        self.homing_speed = int(self.get_parameter("homing_speed").value)
        self.homing_acceleration = int(self.get_parameter("homing_acceleration").value)
        self.homing_timeout_s = float(self.get_parameter("homing_timeout_s").value)
        self.torque_off_after_home = bool(
            self.get_parameter("torque_off_after_home").value
        )
        self.manual_home_valid = bool(
            self.get_parameter("manual_home_valid").value
        )
        self.zero_feedback_position = int(
            self.get_parameter("zero_feedback_position").value
        )
        self.zero_target_position = int(
            self.get_parameter("zero_target_position").value
        )
        if self.zero_feedback_position == 0 and self.zero_target_position != 0:
            self.zero_feedback_position = self.zero_target_position
        self.open_ticks = int(self.get_parameter("open_ticks").value)
        self.max_closed_ticks = int(self.get_parameter("max_closed_ticks").value)
        self.min_safe_ticks = int(self.get_parameter("min_safe_ticks").value)
        self.max_safe_ticks = int(self.get_parameter("max_safe_ticks").value)
        self.max_step_command_ticks = int(
            self.get_parameter("max_step_command_ticks").value
        )
        self.tick_tolerance = int(self.get_parameter("tick_tolerance").value)
        self.open_width_m = float(self.get_parameter("open_width_m").value)
        self.closed_width_m = float(self.get_parameter("closed_width_m").value)
        self.default_speed = int(self.get_parameter("default_speed").value)
        self.default_acceleration = int(self.get_parameter("default_acceleration").value)
        self.force_grasp_speed = int(self.get_parameter("force_grasp_speed").value)
        self.force_current_threshold_raw = int(
            self.get_parameter("force_current_threshold_raw").value
        )
        self.force_load_threshold_raw = int(
            self.get_parameter("force_load_threshold_raw").value
        )
        self.force_contact_confirm_samples = max(
            1, int(self.get_parameter("force_contact_confirm_samples").value)
        )
        self.force_require_slowdown = bool(
            self.get_parameter("force_require_slowdown").value
        )
        self.force_slow_window_samples = max(
            1, int(self.get_parameter("force_slow_window_samples").value)
        )
        self.force_slow_max_delta_ticks = max(
            0, int(self.get_parameter("force_slow_max_delta_ticks").value)
        )
        self.force_min_valid_voltage_v = float(
            self.get_parameter("force_min_valid_voltage_v").value
        )
        self.force_min_valid_temperature_c = int(
            self.get_parameter("force_min_valid_temperature_c").value
        )
        self.force_max_load_jump_raw = max(
            0, int(self.get_parameter("force_max_load_jump_raw").value)
        )
        self.force_max_current_jump_raw = max(
            0, int(self.get_parameter("force_max_current_jump_raw").value)
        )
        self.move_time = int(self.get_parameter("move_time").value)
        self.raw_tolerance = int(self.get_parameter("raw_tolerance").value)
        self.goal_timeout_s = float(self.get_parameter("goal_timeout_s").value)
        self.poll_period_s = float(self.get_parameter("poll_period_s").value)
        self.serial_timeout_s = float(self.get_parameter("serial_timeout_s").value)
        self.serial_write_timeout_s = float(
            self.get_parameter("serial_write_timeout_s").value
        )
        self.state_publish_rate = float(self.get_parameter("state_publish_rate").value)
        self.connect_on_start = bool(self.get_parameter("connect_on_start").value)
        self.torque_on_start = bool(self.get_parameter("torque_on_start").value)

    def _connect(self):
        if self._bus is None or not self._bus.is_open:
            self._bus = Sts3215Bus(
                self.port,
                self.baudrate,
                timeout=self.serial_timeout_s,
                write_timeout=self.serial_write_timeout_s,
            )
            self._bus.open()
        self._connected = True
        self._fault = ""
        return self._bus

    def _set_fault(self, message):
        self._fault = str(message)
        self._connected = False
        with self._io_lock:
            if self._bus is not None:
                try:
                    self._bus.close()
                except Exception:
                    pass
        self.get_logger().warn(self._fault)

    def _clamp_ticks(self, ticks):
        lo = min(self.min_safe_ticks, self.max_safe_ticks)
        hi = max(self.min_safe_ticks, self.max_safe_ticks)
        return max(lo, min(hi, int(round(ticks))))

    def _ticks_to_width(self, ticks):
        span = self.max_closed_ticks - self.open_ticks
        if span == 0:
            return self.open_width_m
        ratio = (float(ticks) - self.open_ticks) / span
        ratio = max(0.0, min(1.0, ratio))
        return self.open_width_m + ratio * (self.closed_width_m - self.open_width_m)

    @staticmethod
    def _effort_magnitude(raw_value):
        if raw_value is None:
            return 0
        return int(raw_value) & 0x7FFF

    def _state_has_valid_position_feedback(self, state):
        if state is None or state.target_position is None:
            return False
        if state.position_error_ticks is None:
            return False
        if int(state.position_error_ticks) < 0:
            return False
        if int(state.position_error_ticks) > self.max_step_command_ticks + self.tick_tolerance:
            return False
        if state.voltage_v is not None and float(state.voltage_v) < 1.0:
            return False
        if state.temperature_c is not None and int(state.temperature_c) <= 0:
            return False
        return True

    @staticmethod
    def _estimate_current_position(state):
        target_position = int(state.target_position)
        position_error = int(state.position_error_ticks or 0)
        if bool(state.position_error_direction):
            return target_position + position_error
        return target_position - position_error

    def _update_relative_from_state(self, state):
        if state.raw_position is not None:
            self._last_raw = int(state.raw_position)
        if not self._state_has_valid_position_feedback(state):
            return
        current_position = self._estimate_current_position(state)
        if not self._homed:
            return
        self._relative_ticks = current_position - self._zero_feedback_position

    def _read_state_locked(self):
        state = self._connect().read_state(self.servo_id)
        self._update_relative_from_state(state)
        self._last_state = state
        self._connected = True
        self._fault = ""
        return state

    def _publish_state(self):
        try:
            with self._io_lock:
                self._read_state_locked()
        except Exception as exc:
            self._set_fault(f"State read failed: {exc}")

        now = self.get_clock().now().to_msg()
        state_msg = self._make_state_message(now)
        self._state_pub.publish(state_msg)

        joint_msg = JointState()
        joint_msg.header.stamp = now
        joint_msg.name = [self.joint_name]
        joint_msg.position = [self._ticks_to_width(self._relative_ticks)]
        joint_msg.velocity = [0.0]
        joint_msg.effort = [float(state_msg.current_raw)]
        self._joint_pub.publish(joint_msg)

    def _make_state_message(self, stamp=None):
        msg = GripperState()
        msg.header.stamp = stamp if stamp is not None else self.get_clock().now().to_msg()
        msg.connected = self._connected
        msg.homed = self._homed
        msg.raw_position = int(self._last_raw)
        msg.relative_ticks = int(self._relative_ticks)
        msg.fault = self._fault
        if self._last_state is not None:
            target_position = int(self._last_state.target_position or 0)
            position_error_ticks = int(self._last_state.position_error_ticks or 0)
            msg.target_position = target_position
            msg.position_error_direction = bool(
                self._last_state.position_error_direction
            )
            msg.position_error_ticks = position_error_ticks
            msg.estimated_position_minus = target_position - position_error_ticks
            msg.estimated_position_plus = target_position + position_error_ticks
            msg.load_raw = int(self._last_state.load_raw or 0)
            msg.current_raw = int(self._last_state.current_raw or 0)
            msg.moving = bool(self._last_state.moving)
            msg.voltage_v = float(self._last_state.voltage_v or 0.0)
            msg.temperature_c = int(self._last_state.temperature_c or 0)
        return msg

    def _goal_callback(self, _goal_request):
        with self._action_lock:
            if self._busy:
                self.get_logger().warn("Rejecting gripper goal while another action is active")
                return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def _move_goal_callback(self, goal_request):
        if goal_request.target_ticks < self.min_safe_ticks or goal_request.target_ticks > self.max_safe_ticks:
            self.get_logger().warn(
                f"Rejecting target_ticks={goal_request.target_ticks}; "
                f"safe range is {self.min_safe_ticks}..{self.max_safe_ticks}"
            )
            return GoalResponse.REJECT
        return self._goal_callback(goal_request)

    def _move_step_goal_callback(self, goal_request):
        if abs(goal_request.delta_ticks) > self.max_step_command_ticks:
            self.get_logger().warn(
                f"Rejecting delta_ticks={goal_request.delta_ticks}; "
                f"maximum step command magnitude is {self.max_step_command_ticks}"
            )
            return GoalResponse.REJECT
        return self._goal_callback(goal_request)

    def _force_goal_callback(self, goal_request):
        if goal_request.max_ticks != 0 and (
            goal_request.max_ticks < self.min_safe_ticks
            or goal_request.max_ticks > self.max_safe_ticks
        ):
            self.get_logger().warn(
                f"Rejecting force grasp max_ticks={goal_request.max_ticks}; "
                f"safe range is {self.min_safe_ticks}..{self.max_safe_ticks}"
            )
            return GoalResponse.REJECT
        return self._goal_callback(goal_request)

    def _cancel_callback(self, _goal_handle):
        return CancelResponse.ACCEPT

    def _begin_action(self):
        with self._action_lock:
            self._busy = True

    def _end_action(self):
        with self._action_lock:
            self._busy = False

    def _stop_motion_locked(self, state=None):
        bus = self._connect()
        if state is None:
            try:
                state = self._read_state_locked()
            except Exception:
                state = None

        if self._state_has_valid_position_feedback(state):
            current_position = self._estimate_current_position(state)
            target_position = int(state.target_position)
            remaining_ticks = target_position - current_position
            stop_delta = -remaining_ticks
            if abs(stop_delta) > self.max_step_command_ticks:
                stop_delta = (
                    self.max_step_command_ticks
                    if stop_delta > 0
                    else -self.max_step_command_ticks
                )
            if self._homed:
                self._relative_ticks = current_position - self._zero_feedback_position
            bus.enable_torque(self.servo_id, True)
            bus.write_step_position(
                self.servo_id,
                stop_delta,
                speed=self.default_speed,
                acceleration=self.default_acceleration,
                move_time=self.move_time,
            )
            self.get_logger().info(
                "Stop-and-hold command sent: "
                f"current_position={current_position}, "
                f"target_position={target_position}, "
                f"remaining_ticks={remaining_ticks}, "
                f"stop_delta={stop_delta}"
            )
            return stop_delta

        bus.enable_torque(self.servo_id, True)
        bus.write_step_position(
            self.servo_id,
            0,
            speed=self.default_speed,
            acceleration=self.default_acceleration,
            move_time=self.move_time,
        )
        self.get_logger().warn(
            "Stop command fell back to zero step because position feedback was invalid"
        )
        return 0

    def _force_sample_valid(self, state, load_raw, current_raw, last_load, last_current):
        if state.voltage_v is None or float(state.voltage_v) < self.force_min_valid_voltage_v:
            return False, "invalid voltage"
        if (
            state.temperature_c is None
            or int(state.temperature_c) < self.force_min_valid_temperature_c
        ):
            return False, "invalid temperature"
        if state.load_raw is None or state.current_raw is None:
            return False, "missing load/current"
        if (
            self.force_max_load_jump_raw > 0
            and last_load is not None
            and abs(load_raw - last_load) > self.force_max_load_jump_raw
        ):
            return False, "load jump"
        if (
            self.force_max_current_jump_raw > 0
            and last_current is not None
            and abs(current_raw - last_current) > self.force_max_current_jump_raw
        ):
            return False, "current jump"
        return True, ""

    def _force_slowdown_detected(self, relative_history):
        if not self.force_require_slowdown:
            return True
        if len(relative_history) < self.force_slow_window_samples:
            return False
        progress = abs(int(relative_history[-1]) - int(relative_history[0]))
        return progress <= self.force_slow_max_delta_ticks

    def _execute_home(self, goal_handle):
        self._begin_action()
        result = HomeGripper.Result()
        try:
            success, message = self._home(goal_handle)
            result.success = success
            result.message = message
            result.raw_position = int(self._last_raw)
            result.relative_ticks = int(self._relative_ticks)
            if success:
                goal_handle.succeed()
            elif goal_handle.is_cancel_requested:
                goal_handle.canceled()
            else:
                goal_handle.abort()
        except Exception as exc:
            result.success = False
            result.message = str(exc)
            self._set_fault(f"Home failed: {exc}")
            self.get_logger().error(f"Home failed: {exc}")
            goal_handle.abort()
        finally:
            self._end_action()
        return result

    def _home(self, goal_handle):
        self._homed = False
        self.get_logger().info(
            "Manual homing: using current gripper position as relative ticks=0"
        )
        if goal_handle.is_cancel_requested:
            return False, "Home canceled"
        with self._io_lock:
            bus = self._connect()
            try:
                bus.enable_torque(self.servo_id, False)
            except Exception:
                pass
            bus.set_angle_limits(self.servo_id, 0, 0)
            bus.set_operating_mode(self.servo_id, Sts3215Bus.MODE_STEP)
            if not self.torque_off_after_home:
                bus.enable_torque(self.servo_id, True)
            state = self._read_state_locked()
            if not self._state_has_valid_position_feedback(state):
                raise Sts3215Error(
                    "Could not read valid target-position feedback for manual home"
                )

        feedback = HomeGripper.Feedback()
        feedback.raw_position = int(self._last_raw)
        feedback.moving = bool(state.moving)
        goal_handle.publish_feedback(feedback)

        self._homed = True
        self._zero_feedback_position = self._estimate_current_position(state)
        self._relative_ticks = self.open_ticks
        torque_state = "off" if self.torque_off_after_home else "on"
        self.get_logger().info(
            "Manual home confirmed; current position is now relative ticks=0, "
            f"zero_feedback_position={self._zero_feedback_position}, "
            f"holding torque is {torque_state}"
        )
        return True, "Manual gripper home confirmed at current position"

    def _execute_move(self, goal_handle):
        self._begin_action()
        result = MoveGripper.Result()
        try:
            if not self._homed:
                raise Sts3215Error(
                    "Gripper zero is unknown; use home for target_ticks or "
                    "move_step for unreferenced Step-mode motion"
                )
            target = self._clamp_ticks(goal_handle.request.target_ticks)
            speed = int(goal_handle.request.speed) or self.default_speed
            success, message = self._move_to_ticks(goal_handle, target, speed)
            result.success = success
            result.message = message
            result.raw_position = int(self._last_raw)
            result.relative_ticks = int(self._relative_ticks)
            if success:
                goal_handle.succeed()
            elif goal_handle.is_cancel_requested:
                goal_handle.canceled()
            else:
                goal_handle.abort()
        except Exception as exc:
            result.success = False
            result.message = str(exc)
            self._set_fault(f"Move failed: {exc}")
            self.get_logger().error(f"Move failed: {exc}")
            goal_handle.abort()
        finally:
            self._end_action()
        return result

    def _execute_move_step(self, goal_handle):
        self._begin_action()
        result = MoveGripperStep.Result()
        try:
            delta_ticks = int(goal_handle.request.delta_ticks)
            speed = int(goal_handle.request.speed) or self.default_speed
            success, moved_ticks, message = self._move_by_step(
                goal_handle,
                delta_ticks,
                speed,
            )
            result.success = success
            result.message = message
            result.raw_position = int(self._last_raw)
            result.moved_ticks = int(moved_ticks)
            if success:
                goal_handle.succeed()
            elif goal_handle.is_cancel_requested:
                goal_handle.canceled()
            else:
                goal_handle.abort()
        except Exception as exc:
            result.success = False
            result.message = str(exc)
            self._set_fault(f"Step move failed: {exc}")
            self.get_logger().error(f"Step move failed: {exc}")
            goal_handle.abort()
        finally:
            self._end_action()
        return result

    def _move_by_step(self, goal_handle, delta_ticks, speed):
        with self._io_lock:
            self._read_state_locked()
            start_raw = self._last_raw
            bus = self._connect()
            mode = bus.read_operating_mode(self.servo_id)
            if mode != Sts3215Bus.MODE_STEP:
                raise Sts3215Error(
                    f"Gripper operating mode is {mode}, expected Step mode "
                    f"{Sts3215Bus.MODE_STEP}"
                )

            # A free step command bypasses the referenced absolute coordinate
            # and its safety range, so the old home reference is no longer
            # trusted even if one existed.
            self._homed = False
            bus.enable_torque(self.servo_id, True)
            bus.write_step_position(
                self.servo_id,
                delta_ticks,
                speed=speed,
                acceleration=self.default_acceleration,
                move_time=self.move_time,
            )

        self.get_logger().info(
            f"Moving gripper by step delta_ticks={delta_ticks} from raw={start_raw}; "
            "absolute zero is now unknown"
        )

        time.sleep(min(0.05, max(0.0, self.poll_period_s)))
        with self._io_lock:
            try:
                state = self._read_state_locked()
            except Exception:
                state = self._last_state

        feedback = MoveGripperStep.Feedback()
        feedback.raw_position = int(self._last_raw)
        feedback.moved_ticks = int(delta_ticks)
        feedback.moving = bool(state.moving) if state is not None else False
        goal_handle.publish_feedback(feedback)

        return True, delta_ticks, "Step relative command sent"

    def _move_to_ticks(self, goal_handle, target_ticks, speed):
        with self._io_lock:
            self._read_state_locked()
            delta = target_ticks - self._relative_ticks
            bus = self._connect()
            bus.enable_torque(self.servo_id, True)
            bus.write_step_position(
                self.servo_id,
                delta,
                speed=speed,
                acceleration=self.default_acceleration,
                move_time=self.move_time,
            )
        self.get_logger().info(
            f"Moving gripper from ticks={self._relative_ticks} to ticks={target_ticks}"
        )

        deadline = time.monotonic() + self.goal_timeout_s
        while time.monotonic() < deadline:
            if goal_handle.is_cancel_requested:
                with self._io_lock:
                    self._stop_motion_locked()
                return False, "Move canceled"
            with self._io_lock:
                state = self._read_state_locked()
            feedback = MoveGripper.Feedback()
            feedback.raw_position = int(self._last_raw)
            feedback.relative_ticks = int(self._relative_ticks)
            feedback.moving = bool(state.moving)
            goal_handle.publish_feedback(feedback)
            position_error = int(state.position_error_ticks or 0)
            if (
                abs(self._relative_ticks - target_ticks) <= self.tick_tolerance
                and position_error <= self.tick_tolerance
                and state.moving is not True
            ):
                return True, "Target relative position reached"
            time.sleep(self.poll_period_s)
        with self._io_lock:
            self._stop_motion_locked()
        return False, f"Move timed out before ticks={target_ticks} was confirmed"

    def _execute_force_grasp(self, goal_handle):
        self._begin_action()
        result = ForceGrasp.Result()
        try:
            if not self._homed:
                raise Sts3215Error("Gripper is not homed")
            max_ticks = int(goal_handle.request.max_ticks) or self.max_closed_ticks
            max_ticks = self._clamp_ticks(max_ticks)
            speed = int(goal_handle.request.speed) or self.force_grasp_speed
            current_threshold = (
                int(goal_handle.request.current_threshold_raw)
                or self.force_current_threshold_raw
            )
            success, contact, message = self._force_grasp(
                goal_handle,
                max_ticks,
                speed,
                current_threshold,
            )
            result.success = success
            result.contact_detected = contact
            result.message = message
            result.raw_position = int(self._last_raw)
            result.relative_ticks = int(self._relative_ticks)
            state = self._last_state
            result.load_raw = int(state.load_raw or 0) if state is not None else 0
            result.current_raw = int(state.current_raw or 0) if state is not None else 0
            if success:
                goal_handle.succeed()
            elif goal_handle.is_cancel_requested:
                goal_handle.canceled()
            else:
                goal_handle.abort()
        except Exception as exc:
            result.success = False
            result.contact_detected = False
            result.message = str(exc)
            self._set_fault(f"Force grasp failed: {exc}")
            self.get_logger().error(f"Force grasp failed: {exc}")
            goal_handle.abort()
        finally:
            self._end_action()
        return result

    def _force_grasp(self, goal_handle, max_ticks, speed, current_threshold):
        with self._io_lock:
            self._read_state_locked()
            delta = max_ticks - self._relative_ticks
            bus = self._connect()
            bus.enable_torque(self.servo_id, True)
            bus.write_step_position(
                self.servo_id,
                delta,
                speed=speed,
                acceleration=self.default_acceleration,
                move_time=self.move_time,
            )
        self.get_logger().info(
            f"Force grasp toward ticks={max_ticks}, current threshold={current_threshold}, "
            f"load threshold={self.force_load_threshold_raw}, "
            f"confirm samples={self.force_contact_confirm_samples}"
        )

        contact_sample_count = 0
        last_valid_load = None
        last_valid_current = None
        invalid_sample_count = 0
        relative_history = deque(maxlen=self.force_slow_window_samples)
        deadline = time.monotonic() + self.goal_timeout_s
        while time.monotonic() < deadline:
            if goal_handle.is_cancel_requested:
                with self._io_lock:
                    self._stop_motion_locked()
                return False, False, "Force grasp canceled"
            with self._io_lock:
                state = self._read_state_locked()
            load_raw = int(state.load_raw or 0)
            current = self._effort_magnitude(state.current_raw)
            feedback = ForceGrasp.Feedback()
            feedback.raw_position = int(self._last_raw)
            feedback.relative_ticks = int(self._relative_ticks)
            feedback.load_raw = int(state.load_raw or 0)
            feedback.current_raw = int(state.current_raw or 0)
            feedback.moving = bool(state.moving)
            goal_handle.publish_feedback(feedback)

            valid_sample, invalid_reason = self._force_sample_valid(
                state,
                load_raw,
                current,
                last_valid_load,
                last_valid_current,
            )
            if not valid_sample:
                invalid_sample_count += 1
                if invalid_sample_count in (1, 10) or invalid_sample_count % 50 == 0:
                    self.get_logger().warn(
                        "Ignoring force-grasp sample: "
                        f"{invalid_reason}; load={load_raw}, current={current}, "
                        f"voltage={state.voltage_v}, temp={state.temperature_c}"
                    )
                time.sleep(self.poll_period_s)
                continue

            last_valid_load = load_raw
            last_valid_current = current
            relative_history.append(int(self._relative_ticks))

            current_contact = current_threshold > 0 and current >= current_threshold
            load_contact = (
                self.force_load_threshold_raw > 0
                and load_raw >= self.force_load_threshold_raw
            )
            slow_contact = self._force_slowdown_detected(relative_history)
            if current_contact and load_contact and slow_contact:
                contact_sample_count += 1
            else:
                contact_sample_count = 0

            if contact_sample_count >= self.force_contact_confirm_samples:
                with self._io_lock:
                    self._stop_motion_locked(state)
                return True, True, (
                    "Contact detected from sustained load/current and slow motion feedback"
                )
            position_error = int(state.position_error_ticks or 0)
            if (
                self._relative_ticks >= max_ticks - self.tick_tolerance
                and position_error <= self.tick_tolerance
                and state.moving is not True
            ):
                with self._io_lock:
                    self._stop_motion_locked()
                return False, False, "Maximum closing position reached without contact"
            time.sleep(self.poll_period_s)
        with self._io_lock:
            self._stop_motion_locked()
        return False, False, "Force grasp timed out without contact"

    def destroy_node(self):
        if self._bus is not None:
            self._bus.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = Sts3215GripperNode()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        executor.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
