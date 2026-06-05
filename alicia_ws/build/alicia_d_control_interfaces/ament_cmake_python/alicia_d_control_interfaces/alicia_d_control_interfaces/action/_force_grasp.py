# generated from rosidl_generator_py/resource/_idl.py.em
# with input from alicia_d_control_interfaces:action/ForceGrasp.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ForceGrasp_Goal(type):
    """Metaclass of message 'ForceGrasp_Goal'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ForceGrasp_Goal(metaclass=Metaclass_ForceGrasp_Goal):
    """Message class 'ForceGrasp_Goal'."""

    __slots__ = [
        '_current_threshold_raw',
        '_max_ticks',
        '_speed',
    ]

    _fields_and_field_types = {
        'current_threshold_raw': 'int32',
        'max_ticks': 'int32',
        'speed': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.current_threshold_raw = kwargs.get('current_threshold_raw', int())
        self.max_ticks = kwargs.get('max_ticks', int())
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
        if self.current_threshold_raw != other.current_threshold_raw:
            return False
        if self.max_ticks != other.max_ticks:
            return False
        if self.speed != other.speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_threshold_raw(self):
        """Message field 'current_threshold_raw'."""
        return self._current_threshold_raw

    @current_threshold_raw.setter
    def current_threshold_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_threshold_raw' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'current_threshold_raw' field must be an integer in [-2147483648, 2147483647]"
        self._current_threshold_raw = value

    @builtins.property
    def max_ticks(self):
        """Message field 'max_ticks'."""
        return self._max_ticks

    @max_ticks.setter
    def max_ticks(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_ticks' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max_ticks' field must be an integer in [-2147483648, 2147483647]"
        self._max_ticks = value

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


class Metaclass_ForceGrasp_Result(type):
    """Metaclass of message 'ForceGrasp_Result'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ForceGrasp_Result(metaclass=Metaclass_ForceGrasp_Result):
    """Message class 'ForceGrasp_Result'."""

    __slots__ = [
        '_success',
        '_contact_detected',
        '_message',
        '_raw_position',
        '_relative_ticks',
        '_load_raw',
        '_current_raw',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'contact_detected': 'boolean',
        'message': 'string',
        'raw_position': 'int32',
        'relative_ticks': 'int32',
        'load_raw': 'int32',
        'current_raw': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.contact_detected = kwargs.get('contact_detected', bool())
        self.message = kwargs.get('message', str())
        self.raw_position = kwargs.get('raw_position', int())
        self.relative_ticks = kwargs.get('relative_ticks', int())
        self.load_raw = kwargs.get('load_raw', int())
        self.current_raw = kwargs.get('current_raw', int())

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
        if self.contact_detected != other.contact_detected:
            return False
        if self.message != other.message:
            return False
        if self.raw_position != other.raw_position:
            return False
        if self.relative_ticks != other.relative_ticks:
            return False
        if self.load_raw != other.load_raw:
            return False
        if self.current_raw != other.current_raw:
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
    def contact_detected(self):
        """Message field 'contact_detected'."""
        return self._contact_detected

    @contact_detected.setter
    def contact_detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'contact_detected' field must be of type 'bool'"
        self._contact_detected = value

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

    @builtins.property
    def load_raw(self):
        """Message field 'load_raw'."""
        return self._load_raw

    @load_raw.setter
    def load_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'load_raw' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'load_raw' field must be an integer in [-2147483648, 2147483647]"
        self._load_raw = value

    @builtins.property
    def current_raw(self):
        """Message field 'current_raw'."""
        return self._current_raw

    @current_raw.setter
    def current_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_raw' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'current_raw' field must be an integer in [-2147483648, 2147483647]"
        self._current_raw = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ForceGrasp_Feedback(type):
    """Metaclass of message 'ForceGrasp_Feedback'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ForceGrasp_Feedback(metaclass=Metaclass_ForceGrasp_Feedback):
    """Message class 'ForceGrasp_Feedback'."""

    __slots__ = [
        '_raw_position',
        '_relative_ticks',
        '_load_raw',
        '_current_raw',
        '_moving',
    ]

    _fields_and_field_types = {
        'raw_position': 'int32',
        'relative_ticks': 'int32',
        'load_raw': 'int32',
        'current_raw': 'int32',
        'moving': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
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
        self.load_raw = kwargs.get('load_raw', int())
        self.current_raw = kwargs.get('current_raw', int())
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
        if self.load_raw != other.load_raw:
            return False
        if self.current_raw != other.current_raw:
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
    def load_raw(self):
        """Message field 'load_raw'."""
        return self._load_raw

    @load_raw.setter
    def load_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'load_raw' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'load_raw' field must be an integer in [-2147483648, 2147483647]"
        self._load_raw = value

    @builtins.property
    def current_raw(self):
        """Message field 'current_raw'."""
        return self._current_raw

    @current_raw.setter
    def current_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_raw' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'current_raw' field must be an integer in [-2147483648, 2147483647]"
        self._current_raw = value

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


class Metaclass_ForceGrasp_SendGoal_Request(type):
    """Metaclass of message 'ForceGrasp_SendGoal_Request'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__send_goal__request

            from alicia_d_control_interfaces.action import ForceGrasp
            if ForceGrasp.Goal.__class__._TYPE_SUPPORT is None:
                ForceGrasp.Goal.__class__.__import_type_support__()

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


class ForceGrasp_SendGoal_Request(metaclass=Metaclass_ForceGrasp_SendGoal_Request):
    """Message class 'ForceGrasp_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'alicia_d_control_interfaces/ForceGrasp_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'ForceGrasp_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Goal
        self.goal = kwargs.get('goal', ForceGrasp_Goal())

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
            from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Goal
            assert \
                isinstance(value, ForceGrasp_Goal), \
                "The 'goal' field must be a sub message of type 'ForceGrasp_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ForceGrasp_SendGoal_Response(type):
    """Metaclass of message 'ForceGrasp_SendGoal_Response'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__send_goal__response

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


class ForceGrasp_SendGoal_Response(metaclass=Metaclass_ForceGrasp_SendGoal_Response):
    """Message class 'ForceGrasp_SendGoal_Response'."""

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


class Metaclass_ForceGrasp_SendGoal(type):
    """Metaclass of service 'ForceGrasp_SendGoal'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__force_grasp__send_goal

            from alicia_d_control_interfaces.action import _force_grasp
            if _force_grasp.Metaclass_ForceGrasp_SendGoal_Request._TYPE_SUPPORT is None:
                _force_grasp.Metaclass_ForceGrasp_SendGoal_Request.__import_type_support__()
            if _force_grasp.Metaclass_ForceGrasp_SendGoal_Response._TYPE_SUPPORT is None:
                _force_grasp.Metaclass_ForceGrasp_SendGoal_Response.__import_type_support__()


class ForceGrasp_SendGoal(metaclass=Metaclass_ForceGrasp_SendGoal):
    from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_SendGoal_Request as Request
    from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ForceGrasp_GetResult_Request(type):
    """Metaclass of message 'ForceGrasp_GetResult_Request'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__get_result__request

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


class ForceGrasp_GetResult_Request(metaclass=Metaclass_ForceGrasp_GetResult_Request):
    """Message class 'ForceGrasp_GetResult_Request'."""

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


class Metaclass_ForceGrasp_GetResult_Response(type):
    """Metaclass of message 'ForceGrasp_GetResult_Response'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__get_result__response

            from alicia_d_control_interfaces.action import ForceGrasp
            if ForceGrasp.Result.__class__._TYPE_SUPPORT is None:
                ForceGrasp.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ForceGrasp_GetResult_Response(metaclass=Metaclass_ForceGrasp_GetResult_Response):
    """Message class 'ForceGrasp_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'alicia_d_control_interfaces/ForceGrasp_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'ForceGrasp_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Result
        self.result = kwargs.get('result', ForceGrasp_Result())

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
            from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Result
            assert \
                isinstance(value, ForceGrasp_Result), \
                "The 'result' field must be a sub message of type 'ForceGrasp_Result'"
        self._result = value


class Metaclass_ForceGrasp_GetResult(type):
    """Metaclass of service 'ForceGrasp_GetResult'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__force_grasp__get_result

            from alicia_d_control_interfaces.action import _force_grasp
            if _force_grasp.Metaclass_ForceGrasp_GetResult_Request._TYPE_SUPPORT is None:
                _force_grasp.Metaclass_ForceGrasp_GetResult_Request.__import_type_support__()
            if _force_grasp.Metaclass_ForceGrasp_GetResult_Response._TYPE_SUPPORT is None:
                _force_grasp.Metaclass_ForceGrasp_GetResult_Response.__import_type_support__()


class ForceGrasp_GetResult(metaclass=Metaclass_ForceGrasp_GetResult):
    from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_GetResult_Request as Request
    from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ForceGrasp_FeedbackMessage(type):
    """Metaclass of message 'ForceGrasp_FeedbackMessage'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__force_grasp__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__force_grasp__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__force_grasp__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__force_grasp__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__force_grasp__feedback_message

            from alicia_d_control_interfaces.action import ForceGrasp
            if ForceGrasp.Feedback.__class__._TYPE_SUPPORT is None:
                ForceGrasp.Feedback.__class__.__import_type_support__()

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


class ForceGrasp_FeedbackMessage(metaclass=Metaclass_ForceGrasp_FeedbackMessage):
    """Message class 'ForceGrasp_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'alicia_d_control_interfaces/ForceGrasp_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['alicia_d_control_interfaces', 'action'], 'ForceGrasp_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Feedback
        self.feedback = kwargs.get('feedback', ForceGrasp_Feedback())

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
            from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Feedback
            assert \
                isinstance(value, ForceGrasp_Feedback), \
                "The 'feedback' field must be a sub message of type 'ForceGrasp_Feedback'"
        self._feedback = value


class Metaclass_ForceGrasp(type):
    """Metaclass of action 'ForceGrasp'."""

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
                'alicia_d_control_interfaces.action.ForceGrasp')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__force_grasp

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from alicia_d_control_interfaces.action import _force_grasp
            if _force_grasp.Metaclass_ForceGrasp_SendGoal._TYPE_SUPPORT is None:
                _force_grasp.Metaclass_ForceGrasp_SendGoal.__import_type_support__()
            if _force_grasp.Metaclass_ForceGrasp_GetResult._TYPE_SUPPORT is None:
                _force_grasp.Metaclass_ForceGrasp_GetResult.__import_type_support__()
            if _force_grasp.Metaclass_ForceGrasp_FeedbackMessage._TYPE_SUPPORT is None:
                _force_grasp.Metaclass_ForceGrasp_FeedbackMessage.__import_type_support__()


class ForceGrasp(metaclass=Metaclass_ForceGrasp):

    # The goal message defined in the action definition.
    from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Goal as Goal
    # The result message defined in the action definition.
    from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Result as Result
    # The feedback message defined in the action definition.
    from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from alicia_d_control_interfaces.action._force_grasp import ForceGrasp_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
