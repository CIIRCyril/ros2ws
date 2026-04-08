# generated from rosidl_generator_py/resource/_idl.py.em
# with input from monitor_msgs:msg/SysMemData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SysMemData(type):
    """Metaclass of message 'SysMemData'."""

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
                'monitor_msgs.msg.SysMemData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sys_mem_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sys_mem_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sys_mem_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sys_mem_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sys_mem_data

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


class SysMemData(metaclass=Metaclass_SysMemData):
    """Message class 'SysMemData'."""

    __slots__ = [
        '_timestamp',
        '_total',
        '_used',
        '_free',
        '_shared',
        '_available',
        '_buffers',
        '_cached',
        '_sreclaimable',
        '_swap_total',
        '_swap_free',
    ]

    _fields_and_field_types = {
        'timestamp': 'builtin_interfaces/Time',
        'total': 'uint64',
        'used': 'uint64',
        'free': 'uint64',
        'shared': 'uint64',
        'available': 'uint64',
        'buffers': 'uint64',
        'cached': 'uint64',
        'sreclaimable': 'uint64',
        'swap_total': 'uint64',
        'swap_free': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Time
        self.timestamp = kwargs.get('timestamp', Time())
        self.total = kwargs.get('total', int())
        self.used = kwargs.get('used', int())
        self.free = kwargs.get('free', int())
        self.shared = kwargs.get('shared', int())
        self.available = kwargs.get('available', int())
        self.buffers = kwargs.get('buffers', int())
        self.cached = kwargs.get('cached', int())
        self.sreclaimable = kwargs.get('sreclaimable', int())
        self.swap_total = kwargs.get('swap_total', int())
        self.swap_free = kwargs.get('swap_free', int())

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
        if self.timestamp != other.timestamp:
            return False
        if self.total != other.total:
            return False
        if self.used != other.used:
            return False
        if self.free != other.free:
            return False
        if self.shared != other.shared:
            return False
        if self.available != other.available:
            return False
        if self.buffers != other.buffers:
            return False
        if self.cached != other.cached:
            return False
        if self.sreclaimable != other.sreclaimable:
            return False
        if self.swap_total != other.swap_total:
            return False
        if self.swap_free != other.swap_free:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'timestamp' field must be a sub message of type 'Time'"
        self._timestamp = value

    @builtins.property
    def total(self):
        """Message field 'total'."""
        return self._total

    @total.setter
    def total(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'total' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'total' field must be an unsigned integer in [0, 18446744073709551615]"
        self._total = value

    @builtins.property
    def used(self):
        """Message field 'used'."""
        return self._used

    @used.setter
    def used(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'used' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'used' field must be an unsigned integer in [0, 18446744073709551615]"
        self._used = value

    @builtins.property
    def free(self):
        """Message field 'free'."""
        return self._free

    @free.setter
    def free(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'free' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'free' field must be an unsigned integer in [0, 18446744073709551615]"
        self._free = value

    @builtins.property
    def shared(self):
        """Message field 'shared'."""
        return self._shared

    @shared.setter
    def shared(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shared' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'shared' field must be an unsigned integer in [0, 18446744073709551615]"
        self._shared = value

    @builtins.property
    def available(self):
        """Message field 'available'."""
        return self._available

    @available.setter
    def available(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'available' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'available' field must be an unsigned integer in [0, 18446744073709551615]"
        self._available = value

    @builtins.property
    def buffers(self):
        """Message field 'buffers'."""
        return self._buffers

    @buffers.setter
    def buffers(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'buffers' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'buffers' field must be an unsigned integer in [0, 18446744073709551615]"
        self._buffers = value

    @builtins.property
    def cached(self):
        """Message field 'cached'."""
        return self._cached

    @cached.setter
    def cached(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cached' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'cached' field must be an unsigned integer in [0, 18446744073709551615]"
        self._cached = value

    @builtins.property
    def sreclaimable(self):
        """Message field 'sreclaimable'."""
        return self._sreclaimable

    @sreclaimable.setter
    def sreclaimable(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sreclaimable' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'sreclaimable' field must be an unsigned integer in [0, 18446744073709551615]"
        self._sreclaimable = value

    @builtins.property
    def swap_total(self):
        """Message field 'swap_total'."""
        return self._swap_total

    @swap_total.setter
    def swap_total(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'swap_total' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'swap_total' field must be an unsigned integer in [0, 18446744073709551615]"
        self._swap_total = value

    @builtins.property
    def swap_free(self):
        """Message field 'swap_free'."""
        return self._swap_free

    @swap_free.setter
    def swap_free(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'swap_free' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'swap_free' field must be an unsigned integer in [0, 18446744073709551615]"
        self._swap_free = value
