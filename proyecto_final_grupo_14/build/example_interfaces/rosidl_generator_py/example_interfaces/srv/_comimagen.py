# generated from rosidl_generator_py/resource/_idl.py.em
# with input from example_interfaces:srv/Comimagen.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Comimagen_Request(type):
    """Metaclass of message 'Comimagen_Request'."""

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
            module = import_type_support('example_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'example_interfaces.srv.Comimagen_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__comimagen__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__comimagen__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__comimagen__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__comimagen__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__comimagen__request

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Comimagen_Request(metaclass=Metaclass_Comimagen_Request):
    """Message class 'Comimagen_Request'."""

    __slots__ = [
        '_imagen',
        '_banner',
    ]

    _fields_and_field_types = {
        'imagen': 'sensor_msgs/Image',
        'banner': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import Image
        self.imagen = kwargs.get('imagen', Image())
        self.banner = kwargs.get('banner', int())

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
        if self.imagen != other.imagen:
            return False
        if self.banner != other.banner:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def imagen(self):
        """Message field 'imagen'."""
        return self._imagen

    @imagen.setter
    def imagen(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'imagen' field must be a sub message of type 'Image'"
        self._imagen = value

    @builtins.property
    def banner(self):
        """Message field 'banner'."""
        return self._banner

    @banner.setter
    def banner(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'banner' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'banner' field must be an integer in [-2147483648, 2147483647]"
        self._banner = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Comimagen_Response(type):
    """Metaclass of message 'Comimagen_Response'."""

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
            module = import_type_support('example_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'example_interfaces.srv.Comimagen_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__comimagen__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__comimagen__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__comimagen__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__comimagen__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__comimagen__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Comimagen_Response(metaclass=Metaclass_Comimagen_Response):
    """Message class 'Comimagen_Response'."""

    __slots__ = [
        '_finalizo',
    ]

    _fields_and_field_types = {
        'finalizo': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.finalizo = kwargs.get('finalizo', str())

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
        if self.finalizo != other.finalizo:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def finalizo(self):
        """Message field 'finalizo'."""
        return self._finalizo

    @finalizo.setter
    def finalizo(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'finalizo' field must be of type 'str'"
        self._finalizo = value


class Metaclass_Comimagen(type):
    """Metaclass of service 'Comimagen'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('example_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'example_interfaces.srv.Comimagen')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__comimagen

            from example_interfaces.srv import _comimagen
            if _comimagen.Metaclass_Comimagen_Request._TYPE_SUPPORT is None:
                _comimagen.Metaclass_Comimagen_Request.__import_type_support__()
            if _comimagen.Metaclass_Comimagen_Response._TYPE_SUPPORT is None:
                _comimagen.Metaclass_Comimagen_Response.__import_type_support__()


class Comimagen(metaclass=Metaclass_Comimagen):
    from example_interfaces.srv._comimagen import Comimagen_Request as Request
    from example_interfaces.srv._comimagen import Comimagen_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
