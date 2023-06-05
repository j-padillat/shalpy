# generated from rosidl_generator_py/resource/_idl.py.em
# with input from player_interfaces:srv/PlayerHardware.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'times'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PlayerHardware_Request(type):
    """Metaclass of message 'PlayerHardware_Request'."""

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
            module = import_type_support('player_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'player_interfaces.srv.PlayerHardware_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__player_hardware__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__player_hardware__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__player_hardware__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__player_hardware__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__player_hardware__request

            from geometry_msgs.msg import Twist
            if Twist.__class__._TYPE_SUPPORT is None:
                Twist.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlayerHardware_Request(metaclass=Metaclass_PlayerHardware_Request):
    """Message class 'PlayerHardware_Request'."""

    __slots__ = [
        '_nombre',
        '_posiciones',
        '_keys',
        '_times',
    ]

    _fields_and_field_types = {
        'nombre': 'string',
        'posiciones': 'sequence<geometry_msgs/Twist>',
        'keys': 'sequence<string>',
        'times': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Twist')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.nombre = kwargs.get('nombre', str())
        self.posiciones = kwargs.get('posiciones', [])
        self.keys = kwargs.get('keys', [])
        self.times = array.array('d', kwargs.get('times', []))

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
        if self.nombre != other.nombre:
            return False
        if self.posiciones != other.posiciones:
            return False
        if self.keys != other.keys:
            return False
        if self.times != other.times:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nombre(self):
        """Message field 'nombre'."""
        return self._nombre

    @nombre.setter
    def nombre(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'nombre' field must be of type 'str'"
        self._nombre = value

    @builtins.property
    def posiciones(self):
        """Message field 'posiciones'."""
        return self._posiciones

    @posiciones.setter
    def posiciones(self, value):
        if __debug__:
            from geometry_msgs.msg import Twist
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
                 all(isinstance(v, Twist) for v in value) and
                 True), \
                "The 'posiciones' field must be a set or sequence and each value of type 'Twist'"
        self._posiciones = value

    @builtins.property
    def keys(self):
        """Message field 'keys'."""
        return self._keys

    @keys.setter
    def keys(self, value):
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
                "The 'keys' field must be a set or sequence and each value of type 'str'"
        self._keys = value

    @builtins.property
    def times(self):
        """Message field 'times'."""
        return self._times

    @times.setter
    def times(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'times' array.array() must have the type code of 'd'"
            self._times = value
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
                "The 'times' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._times = array.array('d', value)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_PlayerHardware_Response(type):
    """Metaclass of message 'PlayerHardware_Response'."""

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
            module = import_type_support('player_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'player_interfaces.srv.PlayerHardware_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__player_hardware__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__player_hardware__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__player_hardware__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__player_hardware__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__player_hardware__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlayerHardware_Response(metaclass=Metaclass_PlayerHardware_Response):
    """Message class 'PlayerHardware_Response'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


class Metaclass_PlayerHardware(type):
    """Metaclass of service 'PlayerHardware'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('player_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'player_interfaces.srv.PlayerHardware')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__player_hardware

            from player_interfaces.srv import _player_hardware
            if _player_hardware.Metaclass_PlayerHardware_Request._TYPE_SUPPORT is None:
                _player_hardware.Metaclass_PlayerHardware_Request.__import_type_support__()
            if _player_hardware.Metaclass_PlayerHardware_Response._TYPE_SUPPORT is None:
                _player_hardware.Metaclass_PlayerHardware_Response.__import_type_support__()


class PlayerHardware(metaclass=Metaclass_PlayerHardware):
    from player_interfaces.srv._player_hardware import PlayerHardware_Request as Request
    from player_interfaces.srv._player_hardware import PlayerHardware_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
