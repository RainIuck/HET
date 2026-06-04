#!/usr/bin/env bash
set -u

TOOLS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_DIR="$(cd "${TOOLS_DIR}/.." && pwd)"
SETUP_FILE="${WS_DIR}/install/setup.bash"
STAMP="$(date +%Y%m%d_%H%M%S)"
RUN_DIR="${WS_DIR}/experiment_logs/simulation/control_layer_${STAMP}"
ROS_LOG_DIR="${RUN_DIR}/ros_logs"

mkdir -p "${RUN_DIR}" "${ROS_LOG_DIR}"

if [[ ! -f "${SETUP_FILE}" ]]; then
  echo "Missing setup file: ${SETUP_FILE}" | tee "${RUN_DIR}/summary.txt"
  exit 2
fi

set +u
source "${SETUP_FILE}"
set -u
export ROS_LOG_DIR

PIDS=()

log() {
  echo "[$(date '+%F %T')] $*" | tee -a "${RUN_DIR}/summary.txt"
}

cleanup() {
  log "Cleaning up background ROS processes"
  for pid in "${PIDS[@]}"; do
    if kill -0 "${pid}" 2>/dev/null; then
      kill "${pid}" 2>/dev/null || true
    fi
  done
  sleep 2
  for pid in "${PIDS[@]}"; do
    if kill -0 "${pid}" 2>/dev/null; then
      kill -9 "${pid}" 2>/dev/null || true
    fi
  done
}

trap cleanup EXIT

wait_for_service() {
  local service_name="$1"
  local timeout_sec="$2"
  local started
  started="$(date +%s)"

  while true; do
    if ros2 service list 2>/dev/null | grep -qx "${service_name}"; then
      log "Service ready: ${service_name}"
      return 0
    fi

    if (( "$(date +%s)" - started >= timeout_sec )); then
      log "Timed out waiting for service: ${service_name}"
      return 1
    fi

    sleep 1
  done
}

wait_for_action() {
  local action_name="$1"
  local timeout_sec="$2"
  local started
  started="$(date +%s)"

  while true; do
    if ros2 action list 2>/dev/null | grep -qx "${action_name}"; then
      log "Action ready: ${action_name}"
      return 0
    fi

    if (( "$(date +%s)" - started >= timeout_sec )); then
      log "Timed out waiting for action: ${action_name}"
      return 1
    fi

    sleep 1
  done
}

snapshot() {
  local label="$1"
  log "Writing snapshot: ${label}"
  {
    echo "===== ros2 node list ====="
    ros2 node list
    echo
    echo "===== ros2 service list ====="
    ros2 service list
    echo
    echo "===== ros2 topic list ====="
    ros2 topic list
    echo
    echo "===== ros2 control list_controllers ====="
    ros2 control list_controllers
    echo
    echo "===== one joint_states message ====="
    timeout 5s ros2 topic echo --once /joint_states || true
  } > "${RUN_DIR}/${label}.txt" 2>&1
}

log "Experiment directory: ${RUN_DIR}"
log "Starting MoveIt demo launch"
ros2 launch alicia_d_moveit demo.launch.py gripper_type:=50mm > "${RUN_DIR}/moveit_demo.log" 2>&1 &
PIDS+=("$!")

wait_for_service /compute_ik 90 || exit 10
wait_for_service /plan_kinematic_path 90 || exit 11

log "Recording /joint_states"
timeout 120s ros2 topic echo /joint_states > "${RUN_DIR}/joint_states.log" 2>&1 &
PIDS+=("$!")

snapshot "before_arm_motion"

log "Starting mock ThinkGrasp bridge"
ros2 launch alicia_d_thinkgrasp_bridge mock_thinkgrasp_bridge.launch.py \
  > "${RUN_DIR}/mock_bridge.log" 2>&1 &
PIDS+=("$!")

log "Starting arm motion server"
ros2 launch alicia_d_arm_motion arm_motion.launch.py > "${RUN_DIR}/arm_motion.log" 2>&1 &
PIDS+=("$!")

wait_for_service /thinkgrasp/request_grasp 30 || exit 12
wait_for_action /arm_motion/move_to_pose 30 || exit 13

log "Requesting one mock grasp candidate"
ros2 service call /thinkgrasp/request_grasp std_srvs/srv/Trigger "{}" \
  > "${RUN_DIR}/grasp_candidate_request.log" 2>&1

log "Sending one arm motion goal with execute=true"
set +e
timeout 90s ros2 action send_goal /arm_motion/move_to_pose \
  alicia_d_control_interfaces/action/MoveArmToPose \
  "{target_pose: {header: {frame_id: base_link}, pose: {position: {x: 0.15, y: 0.1, z: 0.15}, orientation: {x: 1.0, y: 0.0, z: 0.0, w: 0.0}}}, ik_link_name: gripper_center, max_velocity_scaling: 0.25, max_acceleration_scaling: 0.25, avoid_collisions: false, execute: true}" \
  > "${RUN_DIR}/arm_goal.log" 2>&1
MOCK_RC=$?
set -e

snapshot "after_arm_motion"

if [[ "${MOCK_RC}" -eq 0 ]]; then
  log "Arm motion goal exited successfully"
else
  log "Arm motion goal exited with code ${MOCK_RC}"
fi

log "Done"
exit "${MOCK_RC}"
