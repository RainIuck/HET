#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to alicia_d_control_interfaces__msg__GraspCandidate

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GraspCandidate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grasp_pose: geometry_msgs::msg::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grasp_depth_m: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source: std::string::String,

}



impl Default for GraspCandidate {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GraspCandidate::default())
  }
}

impl rosidl_runtime_rs::Message for GraspCandidate {
  type RmwMsg = super::msg::rmw::GraspCandidate;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        grasp_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.grasp_pose)).into_owned(),
        grasp_depth_m: msg.grasp_depth_m,
        source: msg.source.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        grasp_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.grasp_pose)).into_owned(),
      grasp_depth_m: msg.grasp_depth_m,
        source: msg.source.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      grasp_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.grasp_pose),
      grasp_depth_m: msg.grasp_depth_m,
      source: msg.source.to_string(),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__msg__GripperState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub connected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub homed: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position_error_direction: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position_error_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub estimated_position_minus: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub estimated_position_plus: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub load_raw: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_raw: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moving: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub voltage_v: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub temperature_c: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fault: std::string::String,

}



impl Default for GripperState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GripperState::default())
  }
}

impl rosidl_runtime_rs::Message for GripperState {
  type RmwMsg = super::msg::rmw::GripperState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        connected: msg.connected,
        homed: msg.homed,
        raw_position: msg.raw_position,
        relative_ticks: msg.relative_ticks,
        target_position: msg.target_position,
        position_error_direction: msg.position_error_direction,
        position_error_ticks: msg.position_error_ticks,
        estimated_position_minus: msg.estimated_position_minus,
        estimated_position_plus: msg.estimated_position_plus,
        load_raw: msg.load_raw,
        current_raw: msg.current_raw,
        moving: msg.moving,
        voltage_v: msg.voltage_v,
        temperature_c: msg.temperature_c,
        fault: msg.fault.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      connected: msg.connected,
      homed: msg.homed,
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      target_position: msg.target_position,
      position_error_direction: msg.position_error_direction,
      position_error_ticks: msg.position_error_ticks,
      estimated_position_minus: msg.estimated_position_minus,
      estimated_position_plus: msg.estimated_position_plus,
      load_raw: msg.load_raw,
      current_raw: msg.current_raw,
      moving: msg.moving,
      voltage_v: msg.voltage_v,
      temperature_c: msg.temperature_c,
        fault: msg.fault.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      connected: msg.connected,
      homed: msg.homed,
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      target_position: msg.target_position,
      position_error_direction: msg.position_error_direction,
      position_error_ticks: msg.position_error_ticks,
      estimated_position_minus: msg.estimated_position_minus,
      estimated_position_plus: msg.estimated_position_plus,
      load_raw: msg.load_raw,
      current_raw: msg.current_raw,
      moving: msg.moving,
      voltage_v: msg.voltage_v,
      temperature_c: msg.temperature_c,
      fault: msg.fault.to_string(),
    }
  }
}


