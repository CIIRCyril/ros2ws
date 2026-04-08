# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:msg/NavStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavStatus(type):
    """Metaclass of message 'NavStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NONE': 0,
        'UNKNOWN': 100,
        'GOAL_OCCUPIED': 101,
        'TIMEOUT': 102,
        'NO_VALID_PATH': 103,
        'IDLE': 0,
        'EXECUTE_TASK': 1,
        'CANCELED': 2,
        'FAILED': 3,
        'REACHED_GOAL': 4,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hric_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hric_msgs.msg.NavStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NONE': cls.__constants['NONE'],
            'UNKNOWN': cls.__constants['UNKNOWN'],
            'GOAL_OCCUPIED': cls.__constants['GOAL_OCCUPIED'],
            'TIMEOUT': cls.__constants['TIMEOUT'],
            'NO_VALID_PATH': cls.__constants['NO_VALID_PATH'],
            'IDLE': cls.__constants['IDLE'],
            'EXECUTE_TASK': cls.__constants['EXECUTE_TASK'],
            'CANCELED': cls.__constants['CANCELED'],
            'FAILED': cls.__constants['FAILED'],
            'REACHED_GOAL': cls.__constants['REACHED_GOAL'],
        }

    @property
    def NONE(self):
        """Message constant 'NONE'."""
        return Metaclass_NavStatus.__constants['NONE']

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_NavStatus.__constants['UNKNOWN']

    @property
    def GOAL_OCCUPIED(self):
        """Message constant 'GOAL_OCCUPIED'."""
        return Metaclass_NavStatus.__constants['GOAL_OCCUPIED']

    @property
    def TIMEOUT(self):
        """Message constant 'TIMEOUT'."""
        return Metaclass_NavStatus.__constants['TIMEOUT']

    @property
    def NO_VALID_PATH(self):
        """Message constant 'NO_VALID_PATH'."""
        return Metaclass_NavStatus.__constants['NO_VALID_PATH']

    @property
    def IDLE(self):
        """Message constant 'IDLE'."""
        return Metaclass_NavStatus.__constants['IDLE']

    @property
    def EXECUTE_TASK(self):
        """Message constant 'EXECUTE_TASK'."""
        return Metaclass_NavStatus.__constants['EXECUTE_TASK']

    @property
    def CANCELED(self):
        """Message constant 'CANCELED'."""
        return Metaclass_NavStatus.__constants['CANCELED']

    @property
    def FAILED(self):
        """Message constant 'FAILED'."""
        return Metaclass_NavStatus.__constants['FAILED']

    @property
    def REACHED_GOAL(self):
        """Message constant 'REACHED_GOAL'."""
        return Metaclass_NavStatus.__constants['REACHED_GOAL']


class NavStatus(metaclass=Metaclass_NavStatus):
    """
    Message class 'NavStatus'.

    Constants:
      NONE
      UNKNOWN
      GOAL_OCCUPIED
      TIMEOUT
      NO_VALID_PATH
      IDLE
      EXECUTE_TASK
      CANCELED
      FAILED
      REACHED_GOAL
    """

    __slots__ = [
        '_status',
        '_error_code',
    ]

    _fields_and_field_types = {
        'status': 'uint8',
        'error_code': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        self.error_code = kwargs.get('error_code', int())

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
        if self.error_code != other.error_code:
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
            assert value >= 0 and value < 256, \
                "The 'status' field must be an unsigned integer in [0, 255]"
        self._status = value

    @builtins.property
    def error_code(self):
        """Message field 'error_code'."""
        return self._error_code

    @error_code.setter
    def error_code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'error_code' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'error_code' field must be an unsigned integer in [0, 4294967295]"
        self._error_code = value
