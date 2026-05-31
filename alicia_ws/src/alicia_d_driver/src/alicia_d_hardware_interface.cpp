#include "alicia_d_driver/alicia_d_hardware_interface.hpp"

#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cctype>

namespace alicia_d_driver
{

namespace
{
bool parse_bool_param(const std::string & value)
{
  std::string normalized;
  normalized.reserve(value.size());
  for (char ch : value)
  {
    normalized.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
  }
  return normalized == "true" || normalized == "1" || normalized == "yes" || normalized == "on";
}
}  // namespace

CallbackReturn AliciaDHardwareInterface::on_init(
  const hardware_interface::HardwareInfo & info)
{
  if (hardware_interface::SystemInterface::on_init(info) != CallbackReturn::SUCCESS)
  {
    return CallbackReturn::ERROR;
  }

  // Get parameters from URDF
  port_ = info_.hardware_parameters["port"];
  debug_mode_ = info_.hardware_parameters.count("debug_mode") ? 
                parse_bool_param(info_.hardware_parameters["debug_mode"]) : false;
  use_open_loop_state_ = info_.hardware_parameters.count("use_open_loop_state") ?
                         parse_bool_param(info_.hardware_parameters["use_open_loop_state"]) : false;
  feedback_timeout_s_ = info_.hardware_parameters.count("feedback_timeout_s") ?
                        std::stod(info_.hardware_parameters["feedback_timeout_s"]) : 0.5;
  
  // Gripper type (required: "50mm" or "100mm", default "50mm")
  gripper_type_param_ = info_.hardware_parameters.count("gripper_type") ? 
                         info_.hardware_parameters["gripper_type"] : "50mm";
  
  // Speed control parameter (default 20.0 deg/s)
  default_speed_deg_s_ = info_.hardware_parameters.count("default_speed_deg_s") ? 
                         std::stod(info_.hardware_parameters["default_speed_deg_s"]) : 20.0;
  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"), 
              "Default speed configured: %.1f deg/s", default_speed_deg_s_);

  // Initialize state and command vectors
  hw_positions_state_.resize(info_.joints.size(), 0.0);
  hw_positions_command_.resize(info_.joints.size(), 0.0);
  hw_velocities_state_.resize(info_.joints.size(), 0.0);
  hw_velocities_command_.resize(info_.joints.size(), 0.0);

  for (size_t i = 0; i < info_.joints.size(); ++i)
  {
    for (const auto & state_interface : info_.joints[i].state_interfaces)
    {
      if (state_interface.name == hardware_interface::HW_IF_POSITION &&
          !state_interface.initial_value.empty())
      {
        const double initial_position = std::stod(state_interface.initial_value);
        hw_positions_state_[i] = initial_position;
        hw_positions_command_[i] = initial_position;
      }
    }
  }

  last_write_time_ = rclcpp::Time(0, 0, RCL_STEADY_TIME);
  min_write_period_ = 0.0;  // No rate limiting - send commands every cycle for real-time control

  // Initialize hardware connection status
  hardware_connected_ = false;
  warned_invalid_feedback_ = false;
  warned_gripper_feedback_unavailable_ = false;
  warned_overheat_ = false;

  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"), 
              "Initialized hardware interface (using unified data parser control)");
  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"), 
              "Port: %s, Real-time control enabled", 
              port_.empty() ? "(auto-detect)" : port_.c_str());
  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"),
              "State feedback mode: %s",
              use_open_loop_state_ ? "open-loop command state" : "hardware joint feedback");
  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"),
              "Feedback timeout: %.3f s", feedback_timeout_s_);

  return CallbackReturn::SUCCESS;
}

bool AliciaDHardwareInterface::is_joint_feedback_valid(
  const JointState & joint_state, double now_seconds) const
{
  if (joint_state.angles.size() < 6)
  {
    return false;
  }

  for (size_t i = 0; i < 6; ++i)
  {
    if (!std::isfinite(joint_state.angles[i]))
    {
      return false;
    }
  }

  if (feedback_timeout_s_ > 0.0 && (now_seconds - joint_state.timestamp) > feedback_timeout_s_)
  {
    return false;
  }

  if (joint_state.raw_values.size() >= 6)
  {
    const bool all_raw_zero = std::all_of(
      joint_state.raw_values.begin(), joint_state.raw_values.begin() + 6,
      [](uint16_t value) { return value == 0; });
    if (all_raw_zero)
    {
      return false;
    }
  }
  else
  {
    const bool all_near_negative_pi = std::all_of(
      joint_state.angles.begin(), joint_state.angles.begin() + 6,
      [](double angle) { return std::abs(angle + M_PI) < 1e-3; });
    if (all_near_negative_pi)
    {
      return false;
    }
  }

  if (joint_state.run_status == 0xE2)
  {
    return false;
  }

  switch (joint_state.run_status)
  {
    case 0x00:  // idle
    case 0x01:  // locked
    case 0x10:  // sync
    case 0x11:  // sync_locked
    case 0xE1:  // overheat, still usable as position feedback but unsafe for automatic motion
      return true;
    default:
      return false;
  }
}

bool AliciaDHardwareInterface::is_gripper_feedback_valid(
  const std::optional<SelfCheckData> & self_check_data) const
{
  if (!self_check_data.has_value() || self_check_data->bits.size() <= 9)
  {
    return true;
  }
  return self_check_data->bits[9];
}

void AliciaDHardwareInterface::mirror_commands_to_state()
{
  std::lock_guard<std::mutex> lock(data_mutex_);
  hw_positions_state_ = hw_positions_command_;
  for (size_t i = 0; i < hw_velocities_state_.size(); ++i)
  {
    hw_velocities_state_[i] = i < hw_velocities_command_.size() ? hw_velocities_command_[i] : 0.0;
  }
}

CallbackReturn AliciaDHardwareInterface::on_configure(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"), "Configuring hardware interface...");
  
  // Create serial communicator and data parser control (matching driver node)
  communicator_ = std::make_unique<SerialCommunicator>(port_, debug_mode_);
  data_parser_control_ = std::make_unique<AliciaDDataParserControl>(
      communicator_.get(), rclcpp::get_logger("AliciaDHardwareInterface"), debug_mode_, gripper_type_param_);
  
  return CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> AliciaDHardwareInterface::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;
  
  for (size_t i = 0; i < info_.joints.size(); i++)
  {
    state_interfaces.emplace_back(hardware_interface::StateInterface(
      info_.joints[i].name, hardware_interface::HW_IF_POSITION, &hw_positions_state_[i]));
    state_interfaces.emplace_back(hardware_interface::StateInterface(
      info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_velocities_state_[i]));
  }

  return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> AliciaDHardwareInterface::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;
  
  for (size_t i = 0; i < info_.joints.size(); i++)
  {
    command_interfaces.emplace_back(hardware_interface::CommandInterface(
      info_.joints[i].name, hardware_interface::HW_IF_POSITION, &hw_positions_command_[i]));
    command_interfaces.emplace_back(hardware_interface::CommandInterface(
      info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_velocities_command_[i]));
  }

  return command_interfaces;
}

CallbackReturn AliciaDHardwareInterface::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"), "Activating hardware interface...");
  
  // Try to connect to serial port
  if (communicator_->connect())
  {
    hardware_connected_ = true;
    RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"), 
                "Connected to robot. Starting parsing thread and querying information.");

    // Start parsing thread (matching driver node - background thread for continuous data parsing)
    data_parser_control_->start_parsing_thread();

    // Query all information types (matching driver node)
    data_parser_control_->acquire_info("version", true, 3.0, 0.2);
    data_parser_control_->acquire_info("temperature", true, 2.0, 0.2);
    data_parser_control_->acquire_info("velocity", true, 2.0, 0.2);
    data_parser_control_->acquire_info("self_check", true, 2.0, 0.2);
    
    // Print all available information
    data_parser_control_->print_information();

    // Enable torque using data parser control
    data_parser_control_->torque_control("on");
  }
  else
  {
    hardware_connected_ = false;
    RCLCPP_WARN(rclcpp::get_logger("AliciaDHardwareInterface"), 
                "No hardware connected. Running in simulation/demo mode. "
                "Hardware interface will accept commands but they will not be sent to robot.");
  }

  // Initialize command to current state
  hw_positions_command_ = hw_positions_state_;

  return CallbackReturn::SUCCESS;
}

CallbackReturn AliciaDHardwareInterface::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"), "Deactivating hardware interface...");
  
  // Stop parsing thread (matching driver node) only if hardware was connected
  if (hardware_connected_ && data_parser_control_)
  {
    data_parser_control_->stop_parsing_thread();
  }
  
  // Disconnect from serial port only if hardware was connected
  if (hardware_connected_ && communicator_)
  {
    communicator_->disconnect();
  }
  
  hardware_connected_ = false;

  return CallbackReturn::SUCCESS;
}

return_type AliciaDHardwareInterface::read(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // If hardware is not connected, simulate state updates (copy commands to state for simulation)
  if (!hardware_connected_ || !communicator_ || !communicator_->is_connected() || !data_parser_control_)
  {
    // In simulation mode, update state to match commands (simulate ideal robot)
    mirror_commands_to_state();
    return return_type::OK;
  }

  if (use_open_loop_state_)
  {
    mirror_commands_to_state();
    return return_type::OK;
  }

  static rclcpp::Clock steady_clock(RCL_STEADY_TIME);
  static rclcpp::Time last_joint_request(0, 0, RCL_STEADY_TIME);
  rclcpp::Time now = steady_clock.now();
  if ((now - last_joint_request).seconds() >= 0.05)  // Request at 20 Hz (matching driver node)
  {
    data_parser_control_->acquire_info("joint", false);
    last_joint_request = now;
  }
  
  // Update state from parser (data is parsed by background thread)
  auto joint_state = data_parser_control_->get_joint_state();
  auto velocity_data = data_parser_control_->get_velocity_data();
  auto self_check_data = data_parser_control_->get_self_check_data();
  
  if (!joint_state.has_value() ||
      !is_joint_feedback_valid(*joint_state, now.seconds()))
  {
    if (!warned_invalid_feedback_)
    {
      if (joint_state.has_value())
      {
        RCLCPP_WARN(rclcpp::get_logger("AliciaDHardwareInterface"),
                    "Ignoring invalid Alicia-D joint feedback: status=%s, age=%.3f s. "
                    "Keeping last state instead of mirroring commands.",
                    joint_state->run_status_text.c_str(),
                    now.seconds() - joint_state->timestamp);
      }
      else
      {
        RCLCPP_WARN(rclcpp::get_logger("AliciaDHardwareInterface"),
                    "No Alicia-D joint feedback received yet. Keeping last state instead of mirroring commands.");
      }
      warned_invalid_feedback_ = true;
    }
    return return_type::OK;
  }

  warned_invalid_feedback_ = false;

  if (joint_state->run_status == 0xE1 && !warned_overheat_)
  {
    RCLCPP_WARN(rclcpp::get_logger("AliciaDHardwareInterface"),
                "Alicia-D reported overheat status. Position feedback is still used, "
                "but automatic motion should be treated as unsafe until this clears.");
    warned_overheat_ = true;
  }
  else if (joint_state->run_status != 0xE1)
  {
    warned_overheat_ = false;
  }

  {
    std::lock_guard<std::mutex> lock(data_mutex_);
    
    // Update joint positions (first 6 joints)
    for (size_t i = 0; i < 6 && i < joint_state->angles.size() && i < hw_positions_state_.size(); ++i)
    {
      hw_positions_state_[i] = joint_state->angles[i];
    }
    
    if (hw_positions_state_.size() > 6)
    {
      if (is_gripper_feedback_valid(self_check_data))
      {
        hw_positions_state_[6] = data_parser_control_->gripper_value_to_position(joint_state->gripper);
        warned_gripper_feedback_unavailable_ = false;
      }
      else
      {
        hw_positions_state_[6] = hw_positions_command_[6];
        if (!warned_gripper_feedback_unavailable_)
        {
          RCLCPP_WARN(rclcpp::get_logger("AliciaDHardwareInterface"),
                      "Alicia-D gripper self-check bit_9 is fault. "
                      "Using real 6-axis arm feedback, but mirroring gripper command state.");
          warned_gripper_feedback_unavailable_ = true;
        }
      }
    }
    
    // Update velocities if available
    if (velocity_data.has_value() && velocity_data->velocities.size() >= 6)
    {
      // Convert from deg/s to rad/s for first 6 joints
      for (size_t i = 0; i < 6 && i < velocity_data->velocities.size() && i < hw_velocities_state_.size(); ++i)
      {
        hw_velocities_state_[i] = velocity_data->velocities[i] * M_PI / 180.0;
      }
      // Gripper velocity (if available, otherwise 0)
      if (hw_velocities_state_.size() > 6)
      {
        hw_velocities_state_[6] = 0.0;  // Gripper velocity not typically reported
      }
    }
  }

  return return_type::OK;
}

return_type AliciaDHardwareInterface::write(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // If hardware is not connected, simulate command acceptance (state will be updated in read())
  if (!hardware_connected_ || !communicator_ || !communicator_->is_connected() || !data_parser_control_)
  {
    // In simulation mode, commands are accepted but not sent to hardware
    // The read() method will copy commands to state to simulate movement
    return return_type::OK;
  }

  // Real-time control: send commands every cycle (no rate limiting)
  // The robot hardware can handle high-frequency commands for smooth real-time control
  
  std::lock_guard<std::mutex> lock(data_mutex_);
  
  // Log once when we start sending commands (first call after initialization)
  static bool first_write = true;
  if (first_write)
  {
    RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"),
                "Starting to send joint commands with speed: %.1f deg/s", default_speed_deg_s_);
    first_write = false;
  }
  
  // Extract joint angles (first 6 joints)
  std::vector<double> joint_angles;
  for (size_t i = 0; i < 6 && i < hw_positions_command_.size(); ++i)
  {
    joint_angles.push_back(hw_positions_command_[i]);
  }
  
  // Extract gripper position and convert to value (0-1000)
  double gripper_value = -1.0;
  if (hw_positions_command_.size() > 6)
  {
    gripper_value = data_parser_control_->gripper_position_to_value(hw_positions_command_[6]);
  }
  
  double speed_deg_s = default_speed_deg_s_;
  
  // Periodic logging to verify speed is being used (log every 2000 calls = ~10 seconds at 200Hz)
  // or when speed changes significantly
  static int write_count = 0;
  static double last_logged_speed = -1.0;
  write_count++;
  if (write_count % 2000 == 0 || std::abs(speed_deg_s - last_logged_speed) > 1.0)
  {
    RCLCPP_INFO(rclcpp::get_logger("AliciaDHardwareInterface"),
                "Sending joint command with speed: %.1f deg/s", speed_deg_s);
    last_logged_speed = speed_deg_s;
  }
  
  data_parser_control_->set_joint_and_gripper(joint_angles, gripper_value, speed_deg_s);

  return return_type::OK;
}


}  // namespace alicia_d_driver

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(alicia_d_driver::AliciaDHardwareInterface, hardware_interface::SystemInterface)
