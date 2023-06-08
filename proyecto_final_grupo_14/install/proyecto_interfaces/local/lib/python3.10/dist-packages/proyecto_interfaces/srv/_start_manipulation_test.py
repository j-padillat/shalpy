# generated from rosidl_generator_py/resource/_idl.py.em
# with input from proyecto_interfaces:srv/StartManipulationTest.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StartManipulationTest_Request(type):
    """Metaclass of message 'StartManipulationTest_Request'."""

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
            module = import_type_support('proyecto_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'proyecto_interfaces.srv.StartManipulationTest_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__start_manipulation_test__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__start_manipulation_test__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__start_manipulation_test__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__start_manipulation_test__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__start_manipulation_test__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartManipulationTest_Request(metaclass=Metaclass_StartManipulationTest_Request):
    """Message class 'StartManipulationTest_Request'."""

    __slots__ = [
        '_platform',
        '_x',
    ]

    _fields_and_field_types = {
        'platform': 'string',
        'x': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.platform = kwargs.get('platform', str())
        self.x = kwargs.get('x', int())

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
        if self.platform != other.platform:
            return False
        if self.x != other.x:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def platform(self):
        """Message field 'platform'."""
        return self._platform

    @platform.setter
    def platform(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'platform' field must be of type 'str'"
        self._platform = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'x' field must be an integer in [-2147483648, 2147483647]"
        self._x = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_StartManipulationTest_Response(type):
    """Metaclass of message 'StartManipulationTest_Response'."""

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
            module = import_type_support('proyecto_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'proyecto_interfaces.srv.StartManipulationTest_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__start_manipulation_test__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__start_manipulation_test__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__start_manipulation_test__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__start_manipulation_test__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__start_manipulation_test__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartManipulationTest_Response(metaclass=Metaclass_StartManipulationTest_Response):
    """Message class 'StartManipulationTest_Response'."""

    __slots__ = [
        '_answer',
    ]

    _fields_and_field_types = {
        'answer': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.answer = kwargs.get('answer', str())

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
        if self.answer != other.answer:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def answer(self):
        """Message field 'answer'."""
        return self._answer

    @answer.setter
    def answer(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'answer' field must be of type 'str'"
        self._answer = value


class Metaclass_StartManipulationTest(type):
    """Metaclass of service 'StartManipulationTest'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('proyecto_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'proyecto_interfaces.srv.StartManipulationTest')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__start_manipulation_test

            from proyecto_interfaces.srv import _start_manipulation_test
            if _start_manipulation_test.Metaclass_StartManipulationTest_Request._TYPE_SUPPORT is None:
                _start_manipulation_test.Metaclass_StartManipulationTest_Request.__import_type_support__()
            if _start_manipulation_test.Metaclass_StartManipulationTest_Response._TYPE_SUPPORT is None:
                _start_manipulation_test.Metaclass_StartManipulationTest_Response.__import_type_support__()


class StartManipulationTest(metaclass=Metaclass_StartManipulationTest):
    from proyecto_interfaces.srv._start_manipulation_test import StartManipulationTest_Request as Request
    from proyecto_interfaces.srv._start_manipulation_test import StartManipulationTest_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
