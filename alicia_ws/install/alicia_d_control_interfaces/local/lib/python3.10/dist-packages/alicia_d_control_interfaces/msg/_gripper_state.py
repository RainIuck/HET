# generated from rosidl_generator_py/resource/_idl.py.em
# with input from alicia_d_control_interfaces:msg/GripperState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GripperState(type):
    """Metaclass of message 'GripperState'."""

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
                'alicia_d_control_interfaces.msg.GripperState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gripper_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gripper_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gripper_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gripper_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gripper_state

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GripperState(metaclass=Metaclass_GripperState):
    """Message class 'GripperState'."""

    __slots__ = [
        '_header',
        '_connected',
        '_homed',
        '_raw_position',
        '_relative_ticks',
        '_target_position',
        '_position_error_direction',
        '_position_error_ticks',
        '_estimated_position_minus',
        '_estimated_position_plus',
        '_load_raw',
        '_current_raw',
        '_moving',
        '_voltage_v',
        '_temperature_c',
        '_fault',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'connected': 'boolean',
        'homed': 'boolean',
        'raw_position': 'int32',
        'relative_ticks': 'int32',
        'target_position': 'int32',
        'position_error_direction': 'boolean',
        'position_error_ticks': 'int32',
        'estimated_position_minus': 'int32',
        'estimated_position_plus': 'int32',
        'load_raw': 'int32',
        'current_raw': 'int32',
        'moving': 'boolean',
        'voltage_v': 'float',
        'temperature_c': 'int32',
        'fault': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.connected = kwargs.get('connected', bool())
        self.homed = kwargs.get('homed', bool())
        self.raw_position = kwargs.get('raw_position', int())
        self.relative_ticks = kwargs.get('relative_ticks', int())
        self.target_position = kwargs.get('target_position', int())
        self.position_error_direction = kwargs.get('position_error_direction', bool())
        self.position_error_ticks = kwargs.get('position_error_ticks', int())
        self.estimated_position_minus = kwargs.get('estimated_position_minus', int())
        self.estimated_position_plus = kwargs.get('estimated_position_plus', int())
        self.load_raw = kwargs.get('load_raw', int())
        self.current_raw = kwargs.get('current_raw', int())
        self.moving = kwargs.get('moving', bool())
        self.voltage_v = kwargs.get('voltage_v', float())
        self.temperature_c = kwargs.get('temperature_c', int())
        self.fault = kwargs.get('fault', str())

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
        if self.header != other.header:
            return False
        if self.connected != other.connected:
            return False
        if self.homed != other.homed:
            return False
        if self.raw_position != other.raw_position:
            return False
        if self.relative_ticks != other.relative_ticks:
            return False
        if self.target_position != other.target_position:
            return False
        if self.position_error_direction != other.position_error_direction:
            return False
        if self.position_error_ticks != other.position_error_ticks:
            return False
        if self.estimated_position_minus != other.estimated_position_minus:
            return False
        if self.estimated_position_plus != other.estimated_position_plus:
            return False
        if self.load_raw != other.load_raw:
            return False
        if self.current_raw != other.current_raw:
            return False
        if self.moving != other.moving:
            return False
        if self.voltage_v != other.voltage_v:
            return False
        if self.temperature_c != other.temperature_c:
            return False
        if self.fault != other.fault:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def connected(self):
        """Message field 'connected'."""
        return self._connected

    @connected.setter
    def connected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'connected' field must be of type 'bool'"
        self._connected = value

    @builtins.property
    def homed(self):
        """Message field 'homed'."""
        return self._homed

    @homed.setter
    def homed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'homed' field must be of type 'bool'"
        self._homed = value

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
    def target_position(self):
        """Message field 'target_position'."""
        return self._target_position

    @target_position.setter
    def target_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_position' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'target_position' field must be an integer in [-2147483648, 2147483647]"
        self._target_position = value

    @builtins.property
    def position_error_direction(self):
        """Message field 'position_error_direction'."""
        return self._position_error_direction

    @position_error_direction.setter
    def position_error_direction(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'position_error_direction' field must be of type 'bool'"
        self._position_error_direction = value

    @builtins.property
    def position_error_ticks(self):
        """Message field 'position_error_ticks'."""
        return self._position_error_ticks

    @position_error_ticks.setter
    def position_error_ticks(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'position_error_ticks' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'position_error_ticks' field must be an integer in [-2147483648, 2147483647]"
        self._position_error_ticks = value

    @builtins.property
    def estimated_position_minus(self):
        """Message field 'estimated_position_minus'."""
        return self._estimated_position_minus

    @estimated_position_minus.setter
    def estimated_position_minus(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'estimated_position_minus' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'estimated_position_minus' field must be an integer in [-2147483648, 2147483647]"
        self._estimated_position_minus = value

    @builtins.property
    def estimated_position_plus(self):
        """Message field 'estimated_position_plus'."""
        return self._estimated_position_plus

    @estimated_position_plus.setter
    def estimated_position_plus(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'estimated_position_plus' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'estimated_position_plus' field must be an integer in [-2147483648, 2147483647]"
        self._estimated_position_plus = value

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

    @builtins.property
    def voltage_v(self):
        """Message field 'voltage_v'."""
        return self._voltage_v

    @voltage_v.setter
    def voltage_v(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage_v' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'voltage_v' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._voltage_v = value

    @builtins.property
    def temperature_c(self):
        """Message field 'temperature_c'."""
        return self._temperature_c

    @temperature_c.setter
    def temperature_c(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'temperature_c' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'temperature_c' field must be an integer in [-2147483648, 2147483647]"
        self._temperature_c = value

    @builtins.property
    def fault(self):
        """Message field 'fault'."""
        return self._fault

    @fault.setter
    def fault(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'fault' field must be of type 'str'"
        self._fault = value
