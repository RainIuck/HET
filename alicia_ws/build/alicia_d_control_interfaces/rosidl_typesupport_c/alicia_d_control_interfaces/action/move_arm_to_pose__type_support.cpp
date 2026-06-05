// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from alicia_d_control_interfaces:action/MoveArmToPose.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
#include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_Goal_type_support_ids_t;

static const _MoveArmToPose_Goal_type_support_ids_t _MoveArmToPose_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_Goal_type_support_symbol_names_t _MoveArmToPose_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_Goal)),
  }
};

typedef struct _MoveArmToPose_Goal_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_Goal_type_support_data_t;

static _MoveArmToPose_Goal_type_support_data_t _MoveArmToPose_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_Goal_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_Goal)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_Result_type_support_ids_t;

static const _MoveArmToPose_Result_type_support_ids_t _MoveArmToPose_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_Result_type_support_symbol_names_t _MoveArmToPose_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_Result)),
  }
};

typedef struct _MoveArmToPose_Result_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_Result_type_support_data_t;

static _MoveArmToPose_Result_type_support_data_t _MoveArmToPose_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_Result_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_Result_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_Result_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_Result)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_Feedback_type_support_ids_t;

static const _MoveArmToPose_Feedback_type_support_ids_t _MoveArmToPose_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_Feedback_type_support_symbol_names_t _MoveArmToPose_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_Feedback)),
  }
};

typedef struct _MoveArmToPose_Feedback_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_Feedback_type_support_data_t;

static _MoveArmToPose_Feedback_type_support_data_t _MoveArmToPose_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_Feedback_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_Feedback)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_SendGoal_Request_type_support_ids_t;

static const _MoveArmToPose_SendGoal_Request_type_support_ids_t _MoveArmToPose_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_SendGoal_Request_type_support_symbol_names_t _MoveArmToPose_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal_Request)),
  }
};

typedef struct _MoveArmToPose_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_SendGoal_Request_type_support_data_t;

static _MoveArmToPose_SendGoal_Request_type_support_data_t _MoveArmToPose_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_SendGoal_Request_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal_Request)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_SendGoal_Response_type_support_ids_t;

static const _MoveArmToPose_SendGoal_Response_type_support_ids_t _MoveArmToPose_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_SendGoal_Response_type_support_symbol_names_t _MoveArmToPose_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal_Response)),
  }
};

typedef struct _MoveArmToPose_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_SendGoal_Response_type_support_data_t;

static _MoveArmToPose_SendGoal_Response_type_support_data_t _MoveArmToPose_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_SendGoal_Response_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal_Response)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_SendGoal_type_support_ids_t;

static const _MoveArmToPose_SendGoal_type_support_ids_t _MoveArmToPose_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_SendGoal_type_support_symbol_names_t _MoveArmToPose_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal)),
  }
};

typedef struct _MoveArmToPose_SendGoal_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_SendGoal_type_support_data_t;

static _MoveArmToPose_SendGoal_type_support_data_t _MoveArmToPose_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_SendGoal_service_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveArmToPose_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_GetResult_Request_type_support_ids_t;

static const _MoveArmToPose_GetResult_Request_type_support_ids_t _MoveArmToPose_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_GetResult_Request_type_support_symbol_names_t _MoveArmToPose_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult_Request)),
  }
};

typedef struct _MoveArmToPose_GetResult_Request_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_GetResult_Request_type_support_data_t;

static _MoveArmToPose_GetResult_Request_type_support_data_t _MoveArmToPose_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_GetResult_Request_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult_Request)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_GetResult_Response_type_support_ids_t;

static const _MoveArmToPose_GetResult_Response_type_support_ids_t _MoveArmToPose_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_GetResult_Response_type_support_symbol_names_t _MoveArmToPose_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult_Response)),
  }
};

typedef struct _MoveArmToPose_GetResult_Response_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_GetResult_Response_type_support_data_t;

static _MoveArmToPose_GetResult_Response_type_support_data_t _MoveArmToPose_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_GetResult_Response_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult_Response)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_GetResult_type_support_ids_t;

static const _MoveArmToPose_GetResult_type_support_ids_t _MoveArmToPose_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_GetResult_type_support_symbol_names_t _MoveArmToPose_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult)),
  }
};

typedef struct _MoveArmToPose_GetResult_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_GetResult_type_support_data_t;

static _MoveArmToPose_GetResult_type_support_data_t _MoveArmToPose_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_GetResult_service_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveArmToPose_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__struct.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace alicia_d_control_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveArmToPose_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveArmToPose_FeedbackMessage_type_support_ids_t;

static const _MoveArmToPose_FeedbackMessage_type_support_ids_t _MoveArmToPose_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveArmToPose_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveArmToPose_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveArmToPose_FeedbackMessage_type_support_symbol_names_t _MoveArmToPose_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, alicia_d_control_interfaces, action, MoveArmToPose_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, alicia_d_control_interfaces, action, MoveArmToPose_FeedbackMessage)),
  }
};

typedef struct _MoveArmToPose_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _MoveArmToPose_FeedbackMessage_type_support_data_t;

static _MoveArmToPose_FeedbackMessage_type_support_data_t _MoveArmToPose_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveArmToPose_FeedbackMessage_message_typesupport_map = {
  2,
  "alicia_d_control_interfaces",
  &_MoveArmToPose_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_MoveArmToPose_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_MoveArmToPose_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveArmToPose_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveArmToPose_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace alicia_d_control_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_FeedbackMessage)() {
  return &::alicia_d_control_interfaces::action::rosidl_typesupport_c::MoveArmToPose_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "alicia_d_control_interfaces/action/move_arm_to_pose.h"
// already included above
// #include "alicia_d_control_interfaces/action/detail/move_arm_to_pose__type_support.h"

static rosidl_action_type_support_t _alicia_d_control_interfaces__action__MoveArmToPose__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose)()
{
  // Thread-safe by always writing the same values to the static struct
  _alicia_d_control_interfaces__action__MoveArmToPose__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_SendGoal)();
  _alicia_d_control_interfaces__action__MoveArmToPose__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_GetResult)();
  _alicia_d_control_interfaces__action__MoveArmToPose__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _alicia_d_control_interfaces__action__MoveArmToPose__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, alicia_d_control_interfaces, action, MoveArmToPose_FeedbackMessage)();
  _alicia_d_control_interfaces__action__MoveArmToPose__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_alicia_d_control_interfaces__action__MoveArmToPose__typesupport_c;
}

#ifdef __cplusplus
}
#endif
