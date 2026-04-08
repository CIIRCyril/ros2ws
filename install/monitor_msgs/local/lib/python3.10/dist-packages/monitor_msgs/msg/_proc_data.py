# generated from rosidl_generator_py/resource/_idl.py.em
# with input from monitor_msgs:msg/ProcData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ProcData(type):
    """Metaclass of message 'ProcData'."""

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
                'monitor_msgs.msg.ProcData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__proc_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__proc_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__proc_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__proc_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__proc_data

            from monitor_msgs.msg import ProcCpuData
            if ProcCpuData.__class__._TYPE_SUPPORT is None:
                ProcCpuData.__class__.__import_type_support__()

            from monitor_msgs.msg import ProcIoData
            if ProcIoData.__class__._TYPE_SUPPORT is None:
                ProcIoData.__class__.__import_type_support__()

            from monitor_msgs.msg import ProcMemData
            if ProcMemData.__class__._TYPE_SUPPORT is None:
                ProcMemData.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ProcData(metaclass=Metaclass_ProcData):
    """Message class 'ProcData'."""

    __slots__ = [
        '_pid',
        '_name',
        '_active',
        '_cpu_data',
        '_io_data',
        '_mem_data',
    ]

    _fields_and_field_types = {
        'pid': 'uint32',
        'name': 'string',
        'active': 'boolean',
        'cpu_data': 'monitor_msgs/ProcCpuData',
        'io_data': 'monitor_msgs/ProcIoData',
        'mem_data': 'monitor_msgs/ProcMemData',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['monitor_msgs', 'msg'], 'ProcCpuData'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['monitor_msgs', 'msg'], 'ProcIoData'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['monitor_msgs', 'msg'], 'ProcMemData'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pid = kwargs.get('pid', int())
        self.name = kwargs.get('name', str())
        self.active = kwargs.get('active', bool())
        from monitor_msgs.msg import ProcCpuData
        self.cpu_data = kwargs.get('cpu_data', ProcCpuData())
        from monitor_msgs.msg import ProcIoData
        self.io_data = kwargs.get('io_data', ProcIoData())
        from monitor_msgs.msg import ProcMemData
        self.mem_data = kwargs.get('mem_data', ProcMemData())

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
        if self.pid != other.pid:
            return False
        if self.name != other.name:
            return False
        if self.active != other.active:
            return False
        if self.cpu_data != other.cpu_data:
            return False
        if self.io_data != other.io_data:
            return False
        if self.mem_data != other.mem_data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pid(self):
        """Message field 'pid'."""
        return self._pid

    @pid.setter
    def pid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pid' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pid' field must be an unsigned integer in [0, 4294967295]"
        self._pid = value

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def active(self):
        """Message field 'active'."""
        return self._active

    @active.setter
    def active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'active' field must be of type 'bool'"
        self._active = value

    @builtins.property
    def cpu_data(self):
        """Message field 'cpu_data'."""
        return self._cpu_data

    @cpu_data.setter
    def cpu_data(self, value):
        if __debug__:
            from monitor_msgs.msg import ProcCpuData
            assert \
                isinstance(value, ProcCpuData), \
                "The 'cpu_data' field must be a sub message of type 'ProcCpuData'"
        self._cpu_data = value

    @builtins.property
    def io_data(self):
        """Message field 'io_data'."""
        return self._io_data

    @io_data.setter
    def io_data(self, value):
        if __debug__:
            from monitor_msgs.msg import ProcIoData
            assert \
                isinstance(value, ProcIoData), \
                "The 'io_data' field must be a sub message of type 'ProcIoData'"
        self._io_data = value

    @builtins.property
    def mem_data(self):
        """Message field 'mem_data'."""
        return self._mem_data

    @mem_data.setter
    def mem_data(self, value):
        if __debug__:
            from monitor_msgs.msg import ProcMemData
            assert \
                isinstance(value, ProcMemData), \
                "The 'mem_data' field must be a sub message of type 'ProcMemData'"
        self._mem_data = value
