# generated from rosidl_generator_py/resource/_idl.py.em
# with input from alicia_d_control_interfaces:action/MoveArmToJoints.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'joint_positions'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveArmToJoints_Goal(type):
    """Metaclass of message 'MoveArmToJoints_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_Goal(metaclass=Metaclass_MoveArmToJoints_Goal):
    """Message class 'MoveArmToJoints_Goal'."""

    __slots__ = [
        '_joint_names',
        '_joint_positions',
        '_max_velocity_scaling',
        '_max_acceleration_scaling',
        '_execute',
    ]

    _fields_and_field_types = {
        'joint_names': 'sequence<string>',
        'joint_positions': 'sequence<double>',
        'max_velocity_scaling': 'double',
        'max_acceleration_scaling': 'double',
        'execute': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.joint_names = kwargs.get('joint_names', [])
        self.joint_positions = array.array('d', kwargs.get('joint_positions', []))
        self.max_velocity_scaling = kwargs.get('max_velocity_scaling', float())
        self.max_acceleration_scaling = kwargs.get('max_acceleration_scaling', float())
        self.execute = kwargs.get('execute', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.joint_names != other.joint_names:
            return False
        if self.joint_positions != other.joint_positions:
            return False
        if self.max_velocity_scaling != other.max_velocity_scaling:
            return False
        if self.max_acceleration_scaling != other.max_acceleration_scaling:
            return False
        if self.execute != other.execute:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def joint_names(self):
        """Message field 'joint_names'."""
        return self._joint_names

    @joint_names.setter
    def joint_names(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'joint_names' field must be a set or sequence and each value of type 'str'"
        self._joint_names = value

    @builtins.property
    def joint_positions(self):
        """Message field 'joint_positions'."""
        return self._joint_positions

    @joint_positions.setter
    def joint_positions(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'joint_positions' array.array() must have the type code of 'd'"
            self._joint_positions = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'joint_positions' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._joint_positions = array.array('d', value)

    @builtins.property
    def max_velocity_scaling(self):
        """Message field 'max_velocity_scaling'."""
        return self._max_velocity_scaling

    @max_velocity_scaling.setter
    def max_velocity_scaling(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_velocity_scaling' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_velocity_scaling' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_velocity_scaling = value

    @builtins.property
    def max_acceleration_scaling(self):
        """Message field 'max_acceleration_scaling'."""
        return self._max_acceleration_scaling

    @max_acceleration_scaling.setter
    def max_acceleration_scaling(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_acceleration_scaling' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_acceleration_scaling' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_acceleration_scaling = value

    @builtins.property
    def execute(self):
        """Message field 'execute'."""
        return self._execute

    @execute.setter
    def execute(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'execute' field must be of type 'bool'"
        self._execute = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArmToJoints_Result(type):
    """Metaclass of message 'MoveArmToJoints_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_Result(metaclass=Metaclass_MoveArmToJoints_Result):
    """Message class 'MoveArmToJoints_Result'."""

    __slots__ = [
        '_success',
        '_moveit_error_code',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'moveit_error_code': 'int32',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.moveit_error_code = kwargs.get('moveit_error_code', int())
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.moveit_error_code != other.moveit_error_code:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def moveit_error_code(self):
        """Message field 'moveit_error_code'."""
        return self._moveit_error_code

    @moveit_error_code.setter
    def moveit_error_code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'moveit_error_code' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'moveit_error_code' field must be an integer in [-2147483648, 2147483647]"
        self._moveit_error_code = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArmToJoints_Feedback(type):
    """Metaclass of message 'MoveArmToJoints_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_Feedback(metaclass=Metaclass_MoveArmToJoints_Feedback):
    """Message class 'MoveArmToJoints_Feedback'."""

    __slots__ = [
        '_stage',
    ]

    _fields_and_field_types = {
        'stage': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.stage = kwargs.get('stage', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.stage != other.stage:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def stage(self):
        """Message field 'stage'."""
        return self._stage

    @stage.setter
    def stage(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'stage' field must be of type 'str'"
        self._stage = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArmToJoints_SendGoal_Request(type):
    """Metaclass of message 'MoveArmToJoints_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__send_goal__request

            from alicia_d_control_interfaces.action import MoveArmToJoints
            if MoveArmToJoints.Goal.__class__._TYPE_SUPPORT is None:
                MoveArmToJoints.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_SendGoal_Request(metaclass=Metaclass_MoveArmToJoints_SendGoal_Request):
    """Message class 'MoveArmToJoints_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'alicia_d_control_interfaces/MoveArmToJoints_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'MoveArmToJoints_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Goal
        self.goal = kwargs.get('goal', MoveArmToJoints_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Goal
            assert \
                isinstance(value, MoveArmToJoints_Goal), \
                "The 'goal' field must be a sub message of type 'MoveArmToJoints_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArmToJoints_SendGoal_Response(type):
    """Metaclass of message 'MoveArmToJoints_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_SendGoal_Response(metaclass=Metaclass_MoveArmToJoints_SendGoal_Response):
    """Message class 'MoveArmToJoints_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_MoveArmToJoints_SendGoal(type):
    """Metaclass of service 'MoveArmToJoints_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__move_arm_to_joints__send_goal

            from alicia_d_control_interfaces.action import _move_arm_to_joints
            if _move_arm_to_joints.Metaclass_MoveArmToJoints_SendGoal_Request._TYPE_SUPPORT is None:
                _move_arm_to_joints.Metaclass_MoveArmToJoints_SendGoal_Request.__import_type_support__()
            if _move_arm_to_joints.Metaclass_MoveArmToJoints_SendGoal_Response._TYPE_SUPPORT is None:
                _move_arm_to_joints.Metaclass_MoveArmToJoints_SendGoal_Response.__import_type_support__()


class MoveArmToJoints_SendGoal(metaclass=Metaclass_MoveArmToJoints_SendGoal):
    from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_SendGoal_Request as Request
    from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArmToJoints_GetResult_Request(type):
    """Metaclass of message 'MoveArmToJoints_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_GetResult_Request(metaclass=Metaclass_MoveArmToJoints_GetResult_Request):
    """Message class 'MoveArmToJoints_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArmToJoints_GetResult_Response(type):
    """Metaclass of message 'MoveArmToJoints_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__get_result__response

            from alicia_d_control_interfaces.action import MoveArmToJoints
            if MoveArmToJoints.Result.__class__._TYPE_SUPPORT is None:
                MoveArmToJoints.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_GetResult_Response(metaclass=Metaclass_MoveArmToJoints_GetResult_Response):
    """Message class 'MoveArmToJoints_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'alicia_d_control_interfaces/MoveArmToJoints_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'MoveArmToJoints_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Result
        self.result = kwargs.get('result', MoveArmToJoints_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Result
            assert \
                isinstance(value, MoveArmToJoints_Result), \
                "The 'result' field must be a sub message of type 'MoveArmToJoints_Result'"
        self._result = value


class Metaclass_MoveArmToJoints_GetResult(type):
    """Metaclass of service 'MoveArmToJoints_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__move_arm_to_joints__get_result

            from alicia_d_control_interfaces.action import _move_arm_to_joints
            if _move_arm_to_joints.Metaclass_MoveArmToJoints_GetResult_Request._TYPE_SUPPORT is None:
                _move_arm_to_joints.Metaclass_MoveArmToJoints_GetResult_Request.__import_type_support__()
            if _move_arm_to_joints.Metaclass_MoveArmToJoints_GetResult_Response._TYPE_SUPPORT is None:
                _move_arm_to_joints.Metaclass_MoveArmToJoints_GetResult_Response.__import_type_support__()


class MoveArmToJoints_GetResult(metaclass=Metaclass_MoveArmToJoints_GetResult):
    from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_GetResult_Request as Request
    from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArmToJoints_FeedbackMessage(type):
    """Metaclass of message 'MoveArmToJoints_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm_to_joints__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm_to_joints__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm_to_joints__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm_to_joints__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm_to_joints__feedback_message

            from alicia_d_control_interfaces.action import MoveArmToJoints
            if MoveArmToJoints.Feedback.__class__._TYPE_SUPPORT is None:
                MoveArmToJoints.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArmToJoints_FeedbackMessage(metaclass=Metaclass_MoveArmToJoints_FeedbackMessage):
    """Message class 'MoveArmToJoints_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'alicia_d_control_interfaces/MoveArmToJoints_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'MoveArmToJoints_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Feedback
        self.feedback = kwargs.get('feedback', MoveArmToJoints_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Feedback
            assert \
                isinstance(value, MoveArmToJoints_Feedback), \
                "The 'feedback' field must be a sub message of type 'MoveArmToJoints_Feedback'"
        self._feedback = value


class Metaclass_MoveArmToJoints(type):
    """Metaclass of action 'MoveArmToJoints'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('alicia_d_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'alicia_d_control_interfaces.action.MoveArmToJoints')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__move_arm_to_joints

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from alicia_d_control_interfaces.action import _move_arm_to_joints
            if _move_arm_to_joints.Metaclass_MoveArmToJoints_SendGoal._TYPE_SUPPORT is None:
                _move_arm_to_joints.Metaclass_MoveArmToJoints_SendGoal.__import_type_support__()
            if _move_arm_to_joints.Metaclass_MoveArmToJoints_GetResult._TYPE_SUPPORT is None:
                _move_arm_to_joints.Metaclass_MoveArmToJoints_GetResult.__import_type_support__()
            if _move_arm_to_joints.Metaclass_MoveArmToJoints_FeedbackMessage._TYPE_SUPPORT is None:
                _move_arm_to_joints.Metaclass_MoveArmToJoints_FeedbackMessage.__import_type_support__()


class MoveArmToJoints(metaclass=Metaclass_MoveArmToJoints):

    # The goal message defined in the action definition.
    from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Goal as Goal
    # The result message defined in the action definition.
    from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Result as Result
    # The feedback message defined in the action definition.
    from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from alicia_d_control_interfaces.action._move_arm_to_joints import MoveArmToJoints_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
