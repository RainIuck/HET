#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__msg__GraspCandidate() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__msg__GraspCandidate__init(msg: *mut GraspCandidate) -> bool;
    fn alicia_d_control_interfaces__msg__GraspCandidate__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GraspCandidate>, size: usize) -> bool;
    fn alicia_d_control_interfaces__msg__GraspCandidate__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GraspCandidate>);
    fn alicia_d_control_interfaces__msg__GraspCandidate__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GraspCandidate>, out_seq: *mut rosidl_runtime_rs::Sequence<GraspCandidate>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__msg__GraspCandidate
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GraspCandidate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grasp_pose: geometry_msgs::msg::rmw::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grasp_depth_m: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source: rosidl_runtime_rs::String,

}



impl Default for GraspCandidate {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__msg__GraspCandidate__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__msg__GraspCandidate__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GraspCandidate {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__msg__GraspCandidate__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__msg__GraspCandidate__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__msg__GraspCandidate__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GraspCandidate {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GraspCandidate where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/msg/GraspCandidate";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__msg__GraspCandidate() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__msg__GripperState() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__msg__GripperState__init(msg: *mut GripperState) -> bool;
    fn alicia_d_control_interfaces__msg__GripperState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GripperState>, size: usize) -> bool;
    fn alicia_d_control_interfaces__msg__GripperState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GripperState>);
    fn alicia_d_control_interfaces__msg__GripperState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GripperState>, out_seq: *mut rosidl_runtime_rs::Sequence<GripperState>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__msg__GripperState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


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
    pub fault: rosidl_runtime_rs::String,

}



impl Default for GripperState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__msg__GripperState__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__msg__GripperState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GripperState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__msg__GripperState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__msg__GripperState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__msg__GripperState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GripperState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GripperState where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/msg/GripperState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__msg__GripperState() }
  }
}


