# generated from rosidl_generator_py/resource/_idl.py.em
# with input from alicia_d_control_interfaces:action/MoveGripper.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveGripper_Goal(type):
    """Metaclass of message 'MoveGripper_Goal'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveGripper_Goal(metaclass=Metaclass_MoveGripper_Goal):
    """Message class 'MoveGripper_Goal'."""

    __slots__ = [
        '_target_ticks',
        '_speed',
    ]

    _fields_and_field_types = {
        'target_ticks': 'int32',
        'speed': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.target_ticks = kwargs.get('target_ticks', int())
        self.speed = kwargs.get('speed', int())

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
        if self.target_ticks != other.target_ticks:
            return False
        if self.speed != other.speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_ticks(self):
        """Message field 'target_ticks'."""
        return self._target_ticks

    @target_ticks.setter
    def target_ticks(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_ticks' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'target_ticks' field must be an integer in [-2147483648, 2147483647]"
        self._target_ticks = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'speed' field must be an integer in [-2147483648, 2147483647]"
        self._speed = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveGripper_Result(type):
    """Metaclass of message 'MoveGripper_Result'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveGripper_Result(metaclass=Metaclass_MoveGripper_Result):
    """Message class 'MoveGripper_Result'."""

    __slots__ = [
        '_success',
        '_message',
        '_raw_position',
        '_relative_ticks',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'raw_position': 'int32',
        'relative_ticks': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        self.raw_position = kwargs.get('raw_position', int())
        self.relative_ticks = kwargs.get('relative_ticks', int())

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
        if self.message != other.message:
            return False
        if self.raw_position != other.raw_position:
            return False
        if self.relative_ticks != other.relative_ticks:
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

    @builtins.property
    def raw_position(self):
        """Message field 'raw_position'."""
        return self._raw_position

    @raw_position.setter
    def raw_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'raw_position' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'raw_position' field must be an integer in [-2147483648, 2147483647]"
        self._raw_position = value

    @builtins.property
    def relative_ticks(self):
        """Message field 'relative_ticks'."""
        return self._relative_ticks

    @relative_ticks.setter
    def relative_ticks(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'relative_ticks' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'relative_ticks' field must be an integer in [-2147483648, 2147483647]"
        self._relative_ticks = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveGripper_Feedback(type):
    """Metaclass of message 'MoveGripper_Feedback'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveGripper_Feedback(metaclass=Metaclass_MoveGripper_Feedback):
    """Message class 'MoveGripper_Feedback'."""

    __slots__ = [
        '_raw_position',
        '_relative_ticks',
        '_moving',
    ]

    _fields_and_field_types = {
        'raw_position': 'int32',
        'relative_ticks': 'int32',
        'moving': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.raw_position = kwargs.get('raw_position', int())
        self.relative_ticks = kwargs.get('relative_ticks', int())
        self.moving = kwargs.get('moving', bool())

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
        if self.raw_position != other.raw_position:
            return False
        if self.relative_ticks != other.relative_ticks:
            return False
        if self.moving != other.moving:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def raw_position(self):
        """Message field 'raw_position'."""
        return self._raw_position

    @raw_position.setter
    def raw_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'raw_position' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'raw_position' field must be an integer in [-2147483648, 2147483647]"
        self._raw_position = value

    @builtins.property
    def relative_ticks(self):
        """Message field 'relative_ticks'."""
        return self._relative_ticks

    @relative_ticks.setter
    def relative_ticks(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'relative_ticks' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'relative_ticks' field must be an integer in [-2147483648, 2147483647]"
        self._relative_ticks = value

    @builtins.property
    def moving(self):
        """Message field 'moving'."""
        return self._moving

    @moving.setter
    def moving(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'moving' field must be of type 'bool'"
        self._moving = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveGripper_SendGoal_Request(type):
    """Metaclass of message 'MoveGripper_SendGoal_Request'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__send_goal__request

            from alicia_d_control_interfaces.action import MoveGripper
            if MoveGripper.Goal.__class__._TYPE_SUPPORT is None:
                MoveGripper.Goal.__class__.__import_type_support__()

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


class MoveGripper_SendGoal_Request(metaclass=Metaclass_MoveGripper_SendGoal_Request):
    """Message class 'MoveGripper_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'alicia_d_control_interfaces/MoveGripper_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'MoveGripper_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Goal
        self.goal = kwargs.get('goal', MoveGripper_Goal())

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
            from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Goal
            assert \
                isinstance(value, MoveGripper_Goal), \
                "The 'goal' field must be a sub message of type 'MoveGripper_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveGripper_SendGoal_Response(type):
    """Metaclass of message 'MoveGripper_SendGoal_Response'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__send_goal__response

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


class MoveGripper_SendGoal_Response(metaclass=Metaclass_MoveGripper_SendGoal_Response):
    """Message class 'MoveGripper_SendGoal_Response'."""

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


class Metaclass_MoveGripper_SendGoal(type):
    """Metaclass of service 'MoveGripper_SendGoal'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__move_gripper__send_goal

            from alicia_d_control_interfaces.action import _move_gripper
            if _move_gripper.Metaclass_MoveGripper_SendGoal_Request._TYPE_SUPPORT is None:
                _move_gripper.Metaclass_MoveGripper_SendGoal_Request.__import_type_support__()
            if _move_gripper.Metaclass_MoveGripper_SendGoal_Response._TYPE_SUPPORT is None:
                _move_gripper.Metaclass_MoveGripper_SendGoal_Response.__import_type_support__()


class MoveGripper_SendGoal(metaclass=Metaclass_MoveGripper_SendGoal):
    from alicia_d_control_interfaces.action._move_gripper import MoveGripper_SendGoal_Request as Request
    from alicia_d_control_interfaces.action._move_gripper import MoveGripper_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveGripper_GetResult_Request(type):
    """Metaclass of message 'MoveGripper_GetResult_Request'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__get_result__request

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


class MoveGripper_GetResult_Request(metaclass=Metaclass_MoveGripper_GetResult_Request):
    """Message class 'MoveGripper_GetResult_Request'."""

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


class Metaclass_MoveGripper_GetResult_Response(type):
    """Metaclass of message 'MoveGripper_GetResult_Response'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__get_result__response

            from alicia_d_control_interfaces.action import MoveGripper
            if MoveGripper.Result.__class__._TYPE_SUPPORT is None:
                MoveGripper.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveGripper_GetResult_Response(metaclass=Metaclass_MoveGripper_GetResult_Response):
    """Message class 'MoveGripper_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'alicia_d_control_interfaces/MoveGripper_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'MoveGripper_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Result
        self.result = kwargs.get('result', MoveGripper_Result())

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
            from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Result
            assert \
                isinstance(value, MoveGripper_Result), \
                "The 'result' field must be a sub message of type 'MoveGripper_Result'"
        self._result = value


class Metaclass_MoveGripper_GetResult(type):
    """Metaclass of service 'MoveGripper_GetResult'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__move_gripper__get_result

            from alicia_d_control_interfaces.action import _move_gripper
            if _move_gripper.Metaclass_MoveGripper_GetResult_Request._TYPE_SUPPORT is None:
                _move_gripper.Metaclass_MoveGripper_GetResult_Request.__import_type_support__()
            if _move_gripper.Metaclass_MoveGripper_GetResult_Response._TYPE_SUPPORT is None:
                _move_gripper.Metaclass_MoveGripper_GetResult_Response.__import_type_support__()


class MoveGripper_GetResult(metaclass=Metaclass_MoveGripper_GetResult):
    from alicia_d_control_interfaces.action._move_gripper import MoveGripper_GetResult_Request as Request
    from alicia_d_control_interfaces.action._move_gripper import MoveGripper_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveGripper_FeedbackMessage(type):
    """Metaclass of message 'MoveGripper_FeedbackMessage'."""

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
                'alicia_d_control_interfaces.action.MoveGripper_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_gripper__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_gripper__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_gripper__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_gripper__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_gripper__feedback_message

            from alicia_d_control_interfaces.action import MoveGripper
            if MoveGripper.Feedback.__class__._TYPE_SUPPORT is None:
                MoveGripper.Feedback.__class__.__import_type_support__()

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


class MoveGripper_FeedbackMessage(metaclass=Metaclass_MoveGripper_FeedbackMessage):
    """Message class 'MoveGripper_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'alicia_d_control_interfaces/MoveGripper_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'MoveGripper_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Feedback
        self.feedback = kwargs.get('feedback', MoveGripper_Feedback())

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
            from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Feedback
            assert \
                isinstance(value, MoveGripper_Feedback), \
                "The 'feedback' field must be a sub message of type 'MoveGripper_Feedback'"
        self._feedback = value


class Metaclass_MoveGripper(type):
    """Metaclass of action 'MoveGripper'."""

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
                'alicia_d_control_interfaces.action.MoveGripper')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__move_gripper

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from alicia_d_control_interfaces.action import _move_gripper
            if _move_gripper.Metaclass_MoveGripper_SendGoal._TYPE_SUPPORT is None:
                _move_gripper.Metaclass_MoveGripper_SendGoal.__import_type_support__()
            if _move_gripper.Metaclass_MoveGripper_GetResult._TYPE_SUPPORT is None:
                _move_gripper.Metaclass_MoveGripper_GetResult.__import_type_support__()
            if _move_gripper.Metaclass_MoveGripper_FeedbackMessage._TYPE_SUPPORT is None:
                _move_gripper.Metaclass_MoveGripper_FeedbackMessage.__import_type_support__()


class MoveGripper(metaclass=Metaclass_MoveGripper):

    # The goal message defined in the action definition.
    from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Goal as Goal
    # The result message defined in the action definition.
    from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Result as Result
    # The feedback message defined in the action definition.
    from alicia_d_control_interfaces.action._move_gripper import MoveGripper_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from alicia_d_control_interfaces.action._move_gripper import MoveGripper_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from alicia_d_control_interfaces.action._move_gripper import MoveGripper_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from alicia_d_control_interfaces.action._move_gripper import MoveGripper_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
