
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_Goal() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_Goal__init(msg: *mut ForceGrasp_Goal) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Goal>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Goal>);
    fn alicia_d_control_interfaces__action__ForceGrasp_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Goal>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_Goal__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_Goal() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_Result() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_Result__init(msg: *mut ForceGrasp_Result) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Result>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Result>);
    fn alicia_d_control_interfaces__action__ForceGrasp_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Result>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    pub message: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_Result__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_Result where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_Result() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_Feedback__init(msg: *mut ForceGrasp_Feedback) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Feedback>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Feedback>);
    fn alicia_d_control_interfaces__action__ForceGrasp_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_Feedback>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_Feedback__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_Feedback() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__init(msg: *mut ForceGrasp_FeedbackMessage) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_FeedbackMessage>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_FeedbackMessage>);
    fn alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_FeedbackMessage>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ForceGrasp_Feedback,

}



impl Default for ForceGrasp_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_FeedbackMessage() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_Goal() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_Goal__init(msg: *mut HomeGripper_Goal) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Goal>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Goal>);
    fn alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Goal>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for HomeGripper_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_Goal__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_Goal() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_Result() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_Result__init(msg: *mut HomeGripper_Result) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Result>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Result>);
    fn alicia_d_control_interfaces__action__HomeGripper_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Result>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,

}



impl Default for HomeGripper_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_Result__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_Result where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_Result() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_Feedback__init(msg: *mut HomeGripper_Feedback) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Feedback>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Feedback>);
    fn alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_Feedback>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_Feedback__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_Feedback() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__init(msg: *mut HomeGripper_FeedbackMessage) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_FeedbackMessage>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_FeedbackMessage>);
    fn alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_FeedbackMessage>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::HomeGripper_Feedback,

}



impl Default for HomeGripper_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_FeedbackMessage() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_Goal() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Goal__init(msg: *mut MoveArmToJoints_Goal) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Goal>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Goal>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Goal>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_names: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_positions: rosidl_runtime_rs::Sequence<f64>,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_Goal__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_Goal() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_Result() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Result__init(msg: *mut MoveArmToJoints_Result) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Result>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Result>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Result>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    pub message: rosidl_runtime_rs::String,

}



impl Default for MoveArmToJoints_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_Result__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_Result where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_Result() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__init(msg: *mut MoveArmToJoints_Feedback) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Feedback>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Feedback>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_Feedback>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stage: rosidl_runtime_rs::String,

}



impl Default for MoveArmToJoints_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_Feedback() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__init(msg: *mut MoveArmToJoints_FeedbackMessage) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_FeedbackMessage>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_FeedbackMessage>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_FeedbackMessage>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::MoveArmToJoints_Feedback,

}



impl Default for MoveArmToJoints_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_FeedbackMessage() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_Goal() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_Goal__init(msg: *mut MoveArmToPose_Goal) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Goal>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Goal>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Goal>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_pose: geometry_msgs::msg::rmw::PoseStamped,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ik_link_name: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_Goal__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_Goal() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_Result() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_Result__init(msg: *mut MoveArmToPose_Result) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Result>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Result>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Result>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    pub message: rosidl_runtime_rs::String,

}



impl Default for MoveArmToPose_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_Result__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_Result where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_Result() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_Feedback__init(msg: *mut MoveArmToPose_Feedback) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Feedback>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Feedback>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_Feedback>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stage: rosidl_runtime_rs::String,

}



impl Default for MoveArmToPose_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_Feedback__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_Feedback() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__init(msg: *mut MoveArmToPose_FeedbackMessage) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_FeedbackMessage>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_FeedbackMessage>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_FeedbackMessage>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::MoveArmToPose_Feedback,

}



impl Default for MoveArmToPose_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_FeedbackMessage() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_Goal() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_Goal__init(msg: *mut MoveGripper_Goal) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Goal>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Goal>);
    fn alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Goal>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_Goal__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_Goal() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_Result() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_Result__init(msg: *mut MoveGripper_Result) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Result>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Result>);
    fn alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Result>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_ticks: i32,

}



impl Default for MoveGripper_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_Result__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_Result where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_Result() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_Feedback__init(msg: *mut MoveGripper_Feedback) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Feedback>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Feedback>);
    fn alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_Feedback>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_Feedback__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_Feedback() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__init(msg: *mut MoveGripper_FeedbackMessage) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_FeedbackMessage>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_FeedbackMessage>);
    fn alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_FeedbackMessage>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::MoveGripper_Feedback,

}



impl Default for MoveGripper_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_FeedbackMessage() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_Goal() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_Goal__init(msg: *mut MoveGripperStep_Goal) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Goal>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Goal>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Goal>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_Goal__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_Goal() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_Result() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_Result__init(msg: *mut MoveGripperStep_Result) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Result>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Result>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Result>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub raw_position: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub moved_ticks: i32,

}



impl Default for MoveGripperStep_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_Result__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_Result where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_Result() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_Feedback__init(msg: *mut MoveGripperStep_Feedback) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Feedback>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Feedback>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_Feedback>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_Feedback__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_Feedback() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__init(msg: *mut MoveGripperStep_FeedbackMessage) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_FeedbackMessage>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_FeedbackMessage>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_FeedbackMessage>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::MoveGripperStep_Feedback,

}



impl Default for MoveGripperStep_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_FeedbackMessage() }
  }
}




#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__init(msg: *mut ForceGrasp_SendGoal_Request) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Request>);
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ForceGrasp_Goal,

}



impl Default for ForceGrasp_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__init(msg: *mut ForceGrasp_SendGoal_Response) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Response>);
    fn alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_SendGoal_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ForceGrasp_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_SendGoal_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__init(msg: *mut ForceGrasp_GetResult_Request) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Request>);
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ForceGrasp_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__init(msg: *mut ForceGrasp_GetResult_Response) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Response>);
    fn alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceGrasp_GetResult_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceGrasp_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ForceGrasp_Result,

}



impl Default for ForceGrasp_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceGrasp_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceGrasp_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceGrasp_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/ForceGrasp_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__ForceGrasp_GetResult_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__init(msg: *mut HomeGripper_SendGoal_Request) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Request>);
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::HomeGripper_Goal,

}



impl Default for HomeGripper_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_SendGoal_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__init(msg: *mut HomeGripper_SendGoal_Response) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Response>);
    fn alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_SendGoal_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for HomeGripper_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_SendGoal_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__init(msg: *mut HomeGripper_GetResult_Request) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Request>);
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for HomeGripper_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_GetResult_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__init(msg: *mut HomeGripper_GetResult_Response) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Response>);
    fn alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<HomeGripper_GetResult_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__HomeGripper_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HomeGripper_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::HomeGripper_Result,

}



impl Default for HomeGripper_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HomeGripper_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__HomeGripper_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HomeGripper_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HomeGripper_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/HomeGripper_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__HomeGripper_GetResult_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__init(msg: *mut MoveArmToJoints_SendGoal_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Request>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::MoveArmToJoints_Goal,

}



impl Default for MoveArmToJoints_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__init(msg: *mut MoveArmToJoints_SendGoal_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Response>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_SendGoal_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for MoveArmToJoints_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_SendGoal_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__init(msg: *mut MoveArmToJoints_GetResult_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Request>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for MoveArmToJoints_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__init(msg: *mut MoveArmToJoints_GetResult_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Response>);
    fn alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToJoints_GetResult_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToJoints_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::MoveArmToJoints_Result,

}



impl Default for MoveArmToJoints_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToJoints_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToJoints_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToJoints_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToJoints_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToJoints_GetResult_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__init(msg: *mut MoveArmToPose_SendGoal_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Request>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::MoveArmToPose_Goal,

}



impl Default for MoveArmToPose_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__init(msg: *mut MoveArmToPose_SendGoal_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Response>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_SendGoal_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for MoveArmToPose_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_SendGoal_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__init(msg: *mut MoveArmToPose_GetResult_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Request>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for MoveArmToPose_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__init(msg: *mut MoveArmToPose_GetResult_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Response>);
    fn alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArmToPose_GetResult_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArmToPose_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::MoveArmToPose_Result,

}



impl Default for MoveArmToPose_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArmToPose_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArmToPose_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArmToPose_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveArmToPose_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveArmToPose_GetResult_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__init(msg: *mut MoveGripper_SendGoal_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Request>);
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::MoveGripper_Goal,

}



impl Default for MoveGripper_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_SendGoal_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__init(msg: *mut MoveGripper_SendGoal_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Response>);
    fn alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_SendGoal_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for MoveGripper_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_SendGoal_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__init(msg: *mut MoveGripper_GetResult_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Request>);
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for MoveGripper_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_GetResult_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__init(msg: *mut MoveGripper_GetResult_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Response>);
    fn alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripper_GetResult_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripper_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripper_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::MoveGripper_Result,

}



impl Default for MoveGripper_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripper_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripper_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripper_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripper_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripper_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripper_GetResult_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__init(msg: *mut MoveGripperStep_SendGoal_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Request>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::MoveGripperStep_Goal,

}



impl Default for MoveGripperStep_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__init(msg: *mut MoveGripperStep_SendGoal_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Response>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_SendGoal_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for MoveGripperStep_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_SendGoal_Response() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__init(msg: *mut MoveGripperStep_GetResult_Request) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Request>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Request>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Request>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for MoveGripperStep_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Request() }
  }
}


#[link(name = "alicia_d_control_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "alicia_d_control_interfaces__rosidl_generator_c")]
extern "C" {
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__init(msg: *mut MoveGripperStep_GetResult_Response) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Response>, size: usize) -> bool;
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Response>);
    fn alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveGripperStep_GetResult_Response>) -> bool;
}

// Corresponds to alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveGripperStep_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::MoveGripperStep_Result,

}



impl Default for MoveGripperStep_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveGripperStep_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveGripperStep_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveGripperStep_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "alicia_d_control_interfaces/action/MoveGripperStep_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__alicia_d_control_interfaces__action__MoveGripperStep_GetResult_Response() }
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


