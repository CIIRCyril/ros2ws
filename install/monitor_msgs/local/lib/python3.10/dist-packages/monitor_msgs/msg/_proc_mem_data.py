# generated from rosidl_generator_py/resource/_idl.py.em
# with input from monitor_msgs:msg/ProcMemData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ProcMemData(type):
    """Metaclass of message 'ProcMemData'."""

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
                'monitor_msgs.msg.ProcMemData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__proc_mem_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__proc_mem_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__proc_mem_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__proc_mem_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__proc_mem_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ProcMemData(metaclass=Metaclass_ProcMemData):
    """Message class 'ProcMemData'."""

    __slots__ = [
        '_vmsize',
        '_vmrss',
        '_vmshared',
        '_vmexe',
        '_vmdata',
    ]

    _fields_and_field_types = {
        'vmsize': 'uint32',
        'vmrss': 'uint32',
        'vmshared': 'uint32',
        'vmexe': 'uint32',
        'vmdata': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vmsize = kwargs.get('vmsize', int())
        self.vmrss = kwargs.get('vmrss', int())
        self.vmshared = kwargs.get('vmshared', int())
        self.vmexe = kwargs.get('vmexe', int())
        self.vmdata = kwargs.get('vmdata', int())

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
        if self.vmsize != other.vmsize:
            return False
        if self.vmrss != other.vmrss:
            return False
        if self.vmshared != other.vmshared:
            return False
        if self.vmexe != other.vmexe:
            return False
        if self.vmdata != other.vmdata:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def vmsize(self):
        """Message field 'vmsize'."""
        return self._vmsize

    @vmsize.setter
    def vmsize(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vmsize' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'vmsize' field must be an unsigned integer in [0, 4294967295]"
        self._vmsize = value

    @builtins.property
    def vmrss(self):
        """Message field 'vmrss'."""
        return self._vmrss

    @vmrss.setter
    def vmrss(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vmrss' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'vmrss' field must be an unsigned integer in [0, 4294967295]"
        self._vmrss = value

    @builtins.property
    def vmshared(self):
        """Message field 'vmshared'."""
        return self._vmshared

    @vmshared.setter
    def vmshared(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vmshared' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'vmshared' field must be an unsigned integer in [0, 4294967295]"
        self._vmshared = value

    @builtins.property
    def vmexe(self):
        """Message field 'vmexe'."""
        return self._vmexe

    @vmexe.setter
    def vmexe(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vmexe' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'vmexe' field must be an unsigned integer in [0, 4294967295]"
        self._vmexe = value

    @builtins.property
    def vmdata(self):
        """Message field 'vmdata'."""
        return self._vmdata

    @vmdata.setter
    def vmdata(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vmdata' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'vmdata' field must be an unsigned integer in [0, 4294967295]"
        self._vmdata = value
