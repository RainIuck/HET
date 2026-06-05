
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_threshold_raw: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: i32,

}



impl Default for ForceGrasp_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_Goal {
  type RmwMsg = super::action::rmw::ForceGrasp_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        current_threshold_raw: msg.current_threshold_raw,
        max_ticks: msg.max_ticks,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      current_threshold_raw: msg.current_threshold_raw,
      max_ticks: msg.max_ticks,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      current_threshold_raw: msg.current_threshold_raw,
      max_ticks: msg.max_ticks,
      speed: msg.speed,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub contact_detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub load_raw: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_raw: i32,

}



impl Default for ForceGrasp_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_Result::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_Result {
  type RmwMsg = super::action::rmw::ForceGrasp_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        contact_detected: msg.contact_detected,
        message: msg.message.as_str().into(),
        raw_position: msg.raw_position,
        relative_ticks: msg.relative_ticks,
        load_raw: msg.load_raw,
        current_raw: msg.current_raw,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      contact_detected: msg.contact_detected,
        message: msg.message.as_str().into(),
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      load_raw: msg.load_raw,
      current_raw: msg.current_raw,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      contact_detected: msg.contact_detected,
      message: msg.message.to_string(),
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      load_raw: msg.load_raw,
      current_raw: msg.current_raw,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub load_raw: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_raw: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moving: bool,

}



impl Default for ForceGrasp_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_Feedback {
  type RmwMsg = super::action::rmw::ForceGrasp_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        raw_position: msg.raw_position,
        relative_ticks: msg.relative_ticks,
        load_raw: msg.load_raw,
        current_raw: msg.current_raw,
        moving: msg.moving,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      load_raw: msg.load_raw,
      current_raw: msg.current_raw,
      moving: msg.moving,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      load_raw: msg.load_raw,
      current_raw: msg.current_raw,
      moving: msg.moving,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::ForceGrasp_Feedback,

}



impl Default for ForceGrasp_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_FeedbackMessage {
  type RmwMsg = super::action::rmw::ForceGrasp_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::ForceGrasp_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::ForceGrasp_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::ForceGrasp_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for HomeGripper_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_Goal {
  type RmwMsg = super::action::rmw::HomeGripper_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,

}



impl Default for HomeGripper_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_Result::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_Result {
  type RmwMsg = super::action::rmw::HomeGripper_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        raw_position: msg.raw_position,
        relative_ticks: msg.relative_ticks,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moving: bool,

}



impl Default for HomeGripper_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_Feedback {
  type RmwMsg = super::action::rmw::HomeGripper_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        raw_position: msg.raw_position,
        moving: msg.moving,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      raw_position: msg.raw_position,
      moving: msg.moving,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      raw_position: msg.raw_position,
      moving: msg.moving,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::HomeGripper_Feedback,

}



impl Default for HomeGripper_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_FeedbackMessage {
  type RmwMsg = super::action::rmw::HomeGripper_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::HomeGripper_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::HomeGripper_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::HomeGripper_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_names: Vec<std::string::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_positions: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_velocity_scaling: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_acceleration_scaling: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub execute: bool,

}



impl Default for MoveArmToJoints_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_Goal {
  type RmwMsg = super::action::rmw::MoveArmToJoints_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_names: msg.joint_names
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        joint_positions: msg.joint_positions.into(),
        max_velocity_scaling: msg.max_velocity_scaling,
        max_acceleration_scaling: msg.max_acceleration_scaling,
        execute: msg.execute,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_names: msg.joint_names
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        joint_positions: msg.joint_positions.as_slice().into(),
      max_velocity_scaling: msg.max_velocity_scaling,
      max_acceleration_scaling: msg.max_acceleration_scaling,
      execute: msg.execute,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      joint_names: msg.joint_names
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      joint_positions: msg.joint_positions
          .into_iter()
          .collect(),
      max_velocity_scaling: msg.max_velocity_scaling,
      max_acceleration_scaling: msg.max_acceleration_scaling,
      execute: msg.execute,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moveit_error_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for MoveArmToJoints_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_Result::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_Result {
  type RmwMsg = super::action::rmw::MoveArmToJoints_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        moveit_error_code: msg.moveit_error_code,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      moveit_error_code: msg.moveit_error_code,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      moveit_error_code: msg.moveit_error_code,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stage: std::string::String,

}



impl Default for MoveArmToJoints_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_Feedback {
  type RmwMsg = super::action::rmw::MoveArmToJoints_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stage: msg.stage.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stage: msg.stage.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stage: msg.stage.to_string(),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::MoveArmToJoints_Feedback,

}



impl Default for MoveArmToJoints_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_FeedbackMessage {
  type RmwMsg = super::action::rmw::MoveArmToJoints_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::MoveArmToJoints_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::MoveArmToJoints_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::MoveArmToJoints_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_pose: geometry_msgs::msg::PoseStamped,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ik_link_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_velocity_scaling: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_acceleration_scaling: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub avoid_collisions: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub execute: bool,

}



impl Default for MoveArmToPose_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_Goal {
  type RmwMsg = super::action::rmw::MoveArmToPose_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.target_pose)).into_owned(),
        ik_link_name: msg.ik_link_name.as_str().into(),
        max_velocity_scaling: msg.max_velocity_scaling,
        max_acceleration_scaling: msg.max_acceleration_scaling,
        avoid_collisions: msg.avoid_collisions,
        execute: msg.execute,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.target_pose)).into_owned(),
        ik_link_name: msg.ik_link_name.as_str().into(),
      max_velocity_scaling: msg.max_velocity_scaling,
      max_acceleration_scaling: msg.max_acceleration_scaling,
      avoid_collisions: msg.avoid_collisions,
      execute: msg.execute,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target_pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.target_pose),
      ik_link_name: msg.ik_link_name.to_string(),
      max_velocity_scaling: msg.max_velocity_scaling,
      max_acceleration_scaling: msg.max_acceleration_scaling,
      avoid_collisions: msg.avoid_collisions,
      execute: msg.execute,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moveit_error_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for MoveArmToPose_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_Result::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_Result {
  type RmwMsg = super::action::rmw::MoveArmToPose_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        moveit_error_code: msg.moveit_error_code,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      moveit_error_code: msg.moveit_error_code,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      moveit_error_code: msg.moveit_error_code,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stage: std::string::String,

}



impl Default for MoveArmToPose_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_Feedback {
  type RmwMsg = super::action::rmw::MoveArmToPose_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stage: msg.stage.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stage: msg.stage.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stage: msg.stage.to_string(),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::MoveArmToPose_Feedback,

}



impl Default for MoveArmToPose_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_FeedbackMessage {
  type RmwMsg = super::action::rmw::MoveArmToPose_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::MoveArmToPose_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::MoveArmToPose_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::MoveArmToPose_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: i32,

}



impl Default for MoveGripper_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_Goal {
  type RmwMsg = super::action::rmw::MoveGripper_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_ticks: msg.target_ticks,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      target_ticks: msg.target_ticks,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target_ticks: msg.target_ticks,
      speed: msg.speed,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,

}



impl Default for MoveGripper_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_Result::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_Result {
  type RmwMsg = super::action::rmw::MoveGripper_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        raw_position: msg.raw_position,
        relative_ticks: msg.relative_ticks,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moving: bool,

}



impl Default for MoveGripper_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_Feedback {
  type RmwMsg = super::action::rmw::MoveGripper_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        raw_position: msg.raw_position,
        relative_ticks: msg.relative_ticks,
        moving: msg.moving,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      moving: msg.moving,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      raw_position: msg.raw_position,
      relative_ticks: msg.relative_ticks,
      moving: msg.moving,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::MoveGripper_Feedback,

}



impl Default for MoveGripper_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_FeedbackMessage {
  type RmwMsg = super::action::rmw::MoveGripper_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::MoveGripper_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::MoveGripper_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::MoveGripper_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub delta_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: i32,

}



impl Default for MoveGripperStep_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_Goal {
  type RmwMsg = super::action::rmw::MoveGripperStep_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        delta_ticks: msg.delta_ticks,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      delta_ticks: msg.delta_ticks,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      delta_ticks: msg.delta_ticks,
      speed: msg.speed,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moved_ticks: i32,

}



impl Default for MoveGripperStep_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_Result::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_Result {
  type RmwMsg = super::action::rmw::MoveGripperStep_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        raw_position: msg.raw_position,
        moved_ticks: msg.moved_ticks,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      raw_position: msg.raw_position,
      moved_ticks: msg.moved_ticks,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      raw_position: msg.raw_position,
      moved_ticks: msg.moved_ticks,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moved_ticks: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moving: bool,

}



impl Default for MoveGripperStep_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_Feedback {
  type RmwMsg = super::action::rmw::MoveGripperStep_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        raw_position: msg.raw_position,
        moved_ticks: msg.moved_ticks,
        moving: msg.moving,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      raw_position: msg.raw_position,
      moved_ticks: msg.moved_ticks,
      moving: msg.moving,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      raw_position: msg.raw_position,
      moved_ticks: msg.moved_ticks,
      moving: msg.moving,
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::MoveGripperStep_Feedback,

}



impl Default for MoveGripperStep_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_FeedbackMessage {
  type RmwMsg = super::action::rmw::MoveGripperStep_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::MoveGripperStep_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::MoveGripperStep_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::MoveGripperStep_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::ForceGrasp_Goal,

}



impl Default for ForceGrasp_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_SendGoal_Request {
  type RmwMsg = super::action::rmw::ForceGrasp_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::ForceGrasp_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::ForceGrasp_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::ForceGrasp_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for ForceGrasp_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_SendGoal_Response {
  type RmwMsg = super::action::rmw::ForceGrasp_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for ForceGrasp_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_GetResult_Request {
  type RmwMsg = super::action::rmw::ForceGrasp_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::ForceGrasp_Result,

}



impl Default for ForceGrasp_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ForceGrasp_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_GetResult_Response {
  type RmwMsg = super::action::rmw::ForceGrasp_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::ForceGrasp_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::ForceGrasp_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::ForceGrasp_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::HomeGripper_Goal,

}



impl Default for HomeGripper_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_SendGoal_Request {
  type RmwMsg = super::action::rmw::HomeGripper_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::HomeGripper_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::HomeGripper_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::HomeGripper_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for HomeGripper_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_SendGoal_Response {
  type RmwMsg = super::action::rmw::HomeGripper_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for HomeGripper_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_GetResult_Request {
  type RmwMsg = super::action::rmw::HomeGripper_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__HomeGripper_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::HomeGripper_Result,

}



impl Default for HomeGripper_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::HomeGripper_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_GetResult_Response {
  type RmwMsg = super::action::rmw::HomeGripper_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::HomeGripper_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::HomeGripper_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::HomeGripper_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::MoveArmToJoints_Goal,

}



impl Default for MoveArmToJoints_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_SendGoal_Request {
  type RmwMsg = super::action::rmw::MoveArmToJoints_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::MoveArmToJoints_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::MoveArmToJoints_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::MoveArmToJoints_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for MoveArmToJoints_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_SendGoal_Response {
  type RmwMsg = super::action::rmw::MoveArmToJoints_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for MoveArmToJoints_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_GetResult_Request {
  type RmwMsg = super::action::rmw::MoveArmToJoints_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::MoveArmToJoints_Result,

}



impl Default for MoveArmToJoints_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToJoints_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_GetResult_Response {
  type RmwMsg = super::action::rmw::MoveArmToJoints_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::MoveArmToJoints_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::MoveArmToJoints_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::MoveArmToJoints_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::MoveArmToPose_Goal,

}



impl Default for MoveArmToPose_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_SendGoal_Request {
  type RmwMsg = super::action::rmw::MoveArmToPose_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::MoveArmToPose_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::MoveArmToPose_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::MoveArmToPose_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for MoveArmToPose_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_SendGoal_Response {
  type RmwMsg = super::action::rmw::MoveArmToPose_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for MoveArmToPose_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_GetResult_Request {
  type RmwMsg = super::action::rmw::MoveArmToPose_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::MoveArmToPose_Result,

}



impl Default for MoveArmToPose_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveArmToPose_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_GetResult_Response {
  type RmwMsg = super::action::rmw::MoveArmToPose_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::MoveArmToPose_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::MoveArmToPose_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::MoveArmToPose_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::MoveGripper_Goal,

}



impl Default for MoveGripper_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_SendGoal_Request {
  type RmwMsg = super::action::rmw::MoveGripper_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::MoveGripper_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::MoveGripper_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::MoveGripper_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for MoveGripper_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_SendGoal_Response {
  type RmwMsg = super::action::rmw::MoveGripper_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for MoveGripper_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_GetResult_Request {
  type RmwMsg = super::action::rmw::MoveGripper_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripper_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::MoveGripper_Result,

}



impl Default for MoveGripper_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripper_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_GetResult_Response {
  type RmwMsg = super::action::rmw::MoveGripper_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::MoveGripper_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::MoveGripper_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::MoveGripper_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::MoveGripperStep_Goal,

}



impl Default for MoveGripperStep_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_SendGoal_Request {
  type RmwMsg = super::action::rmw::MoveGripperStep_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::MoveGripperStep_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::MoveGripperStep_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::MoveGripperStep_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for MoveGripperStep_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_SendGoal_Response {
  type RmwMsg = super::action::rmw::MoveGripperStep_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for MoveGripperStep_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_GetResult_Request {
  type RmwMsg = super::action::rmw::MoveGripperStep_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::MoveGripperStep_Result,

}



impl Default for MoveGripperStep_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveGripperStep_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_GetResult_Response {
  type RmwMsg = super::action::rmw::MoveGripperStep_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::MoveGripperStep_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::MoveGripperStep_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::MoveGripperStep_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ForceGrasp_SendGoal;

impl rosidl_runtime_rs::Service for ForceGrasp_SendGoal {
    type Request = ForceGrasp_SendGoal_Request;
    type Response = ForceGrasp_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_SendGoal() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ForceGrasp_GetResult;

impl rosidl_runtime_rs::Service for ForceGrasp_GetResult {
    type Request = ForceGrasp_GetResult_Request;
    type Response = ForceGrasp_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_GetResult() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct HomeGripper_SendGoal;

impl rosidl_runtime_rs::Service for HomeGripper_SendGoal {
    type Request = HomeGripper_SendGoal_Request;
    type Response = HomeGripper_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_SendGoal() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct HomeGripper_GetResult;

impl rosidl_runtime_rs::Service for HomeGripper_GetResult {
    type Request = HomeGripper_GetResult_Request;
    type Response = HomeGripper_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_GetResult() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArmToJoints_SendGoal;

impl rosidl_runtime_rs::Service for MoveArmToJoints_SendGoal {
    type Request = MoveArmToJoints_SendGoal_Request;
    type Response = MoveArmToJoints_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArmToJoints_GetResult;

impl rosidl_runtime_rs::Service for MoveArmToJoints_GetResult {
    type Request = MoveArmToJoints_GetResult_Request;
    type Response = MoveArmToJoints_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_GetResult() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArmToPose_SendGoal;

impl rosidl_runtime_rs::Service for MoveArmToPose_SendGoal {
    type Request = MoveArmToPose_SendGoal_Request;
    type Response = MoveArmToPose_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_SendGoal() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArmToPose_GetResult;

impl rosidl_runtime_rs::Service for MoveArmToPose_GetResult {
    type Request = MoveArmToPose_GetResult_Request;
    type Response = MoveArmToPose_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_GetResult() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveGripper_SendGoal;

impl rosidl_runtime_rs::Service for MoveGripper_SendGoal {
    type Request = MoveGripper_SendGoal_Request;
    type Response = MoveGripper_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_SendGoal() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveGripper_GetResult;

impl rosidl_runtime_rs::Service for MoveGripper_GetResult {
    type Request = MoveGripper_GetResult_Request;
    type Response = MoveGripper_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_GetResult() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveGripperStep_SendGoal;

impl rosidl_runtime_rs::Service for MoveGripperStep_SendGoal {
    type Request = MoveGripperStep_SendGoal_Request;
    type Response = MoveGripperStep_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_SendGoal() }
    }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveGripperStep_GetResult;

impl rosidl_runtime_rs::Service for MoveGripperStep_GetResult {
    type Request = MoveGripperStep_GetResult_Request;
    type Response = MoveGripperStep_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_GetResult() }
    }
}






#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp
#[allow(missing_docs, non_camel_case_types)]
pub struct ForceGrasp;

impl rosidl_runtime_rs::Action for ForceGrasp {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = ForceGrasp_Goal;

  /// The result message defined in the action definition.
  type Result = ForceGrasp_Result;

  /// The feedback message defined in the action definition.
  type Feedback = ForceGrasp_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::ForceGrasp_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::ForceGrasp_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::ForceGrasp_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::ForceGrasp_Goal,
  ) -> super::action::rmw::ForceGrasp_SendGoal_Request {
   super::action::rmw::ForceGrasp_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::ForceGrasp_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::ForceGrasp_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::ForceGrasp_SendGoal_Response {
   super::action::rmw::ForceGrasp_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::ForceGrasp_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::ForceGrasp_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::ForceGrasp_Feedback,
  ) -> super::action::rmw::ForceGrasp_FeedbackMessage {
    let mut message = super::action::rmw::ForceGrasp_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::ForceGrasp_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::ForceGrasp_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::ForceGrasp_GetResult_Request {
   super::action::rmw::ForceGrasp_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::ForceGrasp_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::ForceGrasp_Result,
  ) -> super::action::rmw::ForceGrasp_GetResult_Response {
   super::action::rmw::ForceGrasp_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::ForceGrasp_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::ForceGrasp_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__HomeGripper() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper
#[allow(missing_docs, non_camel_case_types)]
pub struct HomeGripper;

impl rosidl_runtime_rs::Action for HomeGripper {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = HomeGripper_Goal;

  /// The result message defined in the action definition.
  type Result = HomeGripper_Result;

  /// The feedback message defined in the action definition.
  type Feedback = HomeGripper_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::HomeGripper_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::HomeGripper_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::HomeGripper_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__HomeGripper() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::HomeGripper_Goal,
  ) -> super::action::rmw::HomeGripper_SendGoal_Request {
   super::action::rmw::HomeGripper_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::HomeGripper_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::HomeGripper_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::HomeGripper_SendGoal_Response {
   super::action::rmw::HomeGripper_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::HomeGripper_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::HomeGripper_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::HomeGripper_Feedback,
  ) -> super::action::rmw::HomeGripper_FeedbackMessage {
    let mut message = super::action::rmw::HomeGripper_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::HomeGripper_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::HomeGripper_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::HomeGripper_GetResult_Request {
   super::action::rmw::HomeGripper_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::HomeGripper_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::HomeGripper_Result,
  ) -> super::action::rmw::HomeGripper_GetResult_Response {
   super::action::rmw::HomeGripper_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::HomeGripper_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::HomeGripper_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArmToJoints;

impl rosidl_runtime_rs::Action for MoveArmToJoints {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = MoveArmToJoints_Goal;

  /// The result message defined in the action definition.
  type Result = MoveArmToJoints_Result;

  /// The feedback message defined in the action definition.
  type Feedback = MoveArmToJoints_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::MoveArmToJoints_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::MoveArmToJoints_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::MoveArmToJoints_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::MoveArmToJoints_Goal,
  ) -> super::action::rmw::MoveArmToJoints_SendGoal_Request {
   super::action::rmw::MoveArmToJoints_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::MoveArmToJoints_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveArmToJoints_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::MoveArmToJoints_SendGoal_Response {
   super::action::rmw::MoveArmToJoints_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::MoveArmToJoints_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::MoveArmToJoints_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::MoveArmToJoints_Feedback,
  ) -> super::action::rmw::MoveArmToJoints_FeedbackMessage {
    let mut message = super::action::rmw::MoveArmToJoints_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::MoveArmToJoints_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveArmToJoints_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::MoveArmToJoints_GetResult_Request {
   super::action::rmw::MoveArmToJoints_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::MoveArmToJoints_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::MoveArmToJoints_Result,
  ) -> super::action::rmw::MoveArmToJoints_GetResult_Response {
   super::action::rmw::MoveArmToJoints_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::MoveArmToJoints_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::MoveArmToJoints_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArmToPose;

impl rosidl_runtime_rs::Action for MoveArmToPose {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = MoveArmToPose_Goal;

  /// The result message defined in the action definition.
  type Result = MoveArmToPose_Result;

  /// The feedback message defined in the action definition.
  type Feedback = MoveArmToPose_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::MoveArmToPose_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::MoveArmToPose_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::MoveArmToPose_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::MoveArmToPose_Goal,
  ) -> super::action::rmw::MoveArmToPose_SendGoal_Request {
   super::action::rmw::MoveArmToPose_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::MoveArmToPose_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveArmToPose_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::MoveArmToPose_SendGoal_Response {
   super::action::rmw::MoveArmToPose_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::MoveArmToPose_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::MoveArmToPose_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::MoveArmToPose_Feedback,
  ) -> super::action::rmw::MoveArmToPose_FeedbackMessage {
    let mut message = super::action::rmw::MoveArmToPose_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::MoveArmToPose_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveArmToPose_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::MoveArmToPose_GetResult_Request {
   super::action::rmw::MoveArmToPose_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::MoveArmToPose_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::MoveArmToPose_Result,
  ) -> super::action::rmw::MoveArmToPose_GetResult_Response {
   super::action::rmw::MoveArmToPose_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::MoveArmToPose_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::MoveArmToPose_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveGripper() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveGripper;

impl rosidl_runtime_rs::Action for MoveGripper {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = MoveGripper_Goal;

  /// The result message defined in the action definition.
  type Result = MoveGripper_Result;

  /// The feedback message defined in the action definition.
  type Feedback = MoveGripper_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::MoveGripper_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::MoveGripper_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::MoveGripper_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveGripper() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::MoveGripper_Goal,
  ) -> super::action::rmw::MoveGripper_SendGoal_Request {
   super::action::rmw::MoveGripper_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::MoveGripper_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveGripper_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::MoveGripper_SendGoal_Response {
   super::action::rmw::MoveGripper_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::MoveGripper_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::MoveGripper_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::MoveGripper_Feedback,
  ) -> super::action::rmw::MoveGripper_FeedbackMessage {
    let mut message = super::action::rmw::MoveGripper_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::MoveGripper_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveGripper_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::MoveGripper_GetResult_Request {
   super::action::rmw::MoveGripper_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::MoveGripper_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::MoveGripper_Result,
  ) -> super::action::rmw::MoveGripper_GetResult_Response {
   super::action::rmw::MoveGripper_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::MoveGripper_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::MoveGripper_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep() -> *const std::ffi::c_void;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveGripperStep;

impl rosidl_runtime_rs::Action for MoveGripperStep {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = MoveGripperStep_Goal;

  /// The result message defined in the action definition.
  type Result = MoveGripperStep_Result;

  /// The feedback message defined in the action definition.
  type Feedback = MoveGripperStep_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::MoveGripperStep_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::MoveGripperStep_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::MoveGripperStep_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::MoveGripperStep_Goal,
  ) -> super::action::rmw::MoveGripperStep_SendGoal_Request {
   super::action::rmw::MoveGripperStep_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::MoveGripperStep_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveGripperStep_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::MoveGripperStep_SendGoal_Response {
   super::action::rmw::MoveGripperStep_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::MoveGripperStep_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::MoveGripperStep_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::MoveGripperStep_Feedback,
  ) -> super::action::rmw::MoveGripperStep_FeedbackMessage {
    let mut message = super::action::rmw::MoveGripperStep_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::MoveGripperStep_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveGripperStep_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::MoveGripperStep_GetResult_Request {
   super::action::rmw::MoveGripperStep_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::MoveGripperStep_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::MoveGripperStep_Result,
  ) -> super::action::rmw::MoveGripperStep_GetResult_Response {
   super::action::rmw::MoveGripperStep_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::MoveGripperStep_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::MoveGripperStep_Result,
  ) {
    (response.status, response.result)
  }
}


