# generated from rosidl_generator_py/resource/_idl.py.em
# with input from monitor_msgs:msg/SysCpuData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SysCpuData(type):
    """Metaclass of message 'SysCpuData'."""

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
            module = import_type_support('monitor_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'monitor_msgs.msg.SysCpuData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sys_cpu_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sys_cpu_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sys_cpu_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sys_cpu_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sys_cpu_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SysCpuData(metaclass=Metaclass_SysCpuData):
    """Message class 'SysCpuData'."""

    __slots__ = [
        '_cpu_num',
        '_cpu_used',
        '_proc_num',
        '_proc_array',
    ]

    _fields_and_field_types = {
        'cpu_num': 'uint8',
        'cpu_used': 'float',
        'proc_num': 'uint32',
        'proc_array': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cpu_num = kwargs.get('cpu_num', int())
        self.cpu_used = kwargs.get('cpu_used', float())
        self.proc_num = kwargs.get('proc_num', int())
        self.proc_array = kwargs.get('proc_array', [])

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
        if self.cpu_num != other.cpu_num:
            return False
        if self.cpu_used != other.cpu_used:
            return False
        if self.proc_num != other.proc_num:
            return False
        if self.proc_array != other.proc_array:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cpu_num(self):
        """Message field 'cpu_num'."""
        return self._cpu_num

    @cpu_num.setter
    def cpu_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cpu_num' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cpu_num' field must be an unsigned integer in [0, 255]"
        self._cpu_num = value

    @builtins.property
    def cpu_used(self):
        """Message field 'cpu_used'."""
        return self._cpu_used

    @cpu_used.setter
    def cpu_used(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cpu_used' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cpu_used' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cpu_used = value

    @builtins.property
    def proc_num(self):
        """Message field 'proc_num'."""
        return self._proc_num

    @proc_num.setter
    def proc_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'proc_num' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'proc_num' field must be an unsigned integer in [0, 4294967295]"
        self._proc_num = value

    @builtins.property
    def proc_array(self):
        """Message field 'proc_array'."""
        return self._proc_array

    @proc_array.setter
    def proc_array(self, value):
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
                "The 'proc_array' field must be a set or sequence and each value of type 'str'"
        self._proc_array = value
