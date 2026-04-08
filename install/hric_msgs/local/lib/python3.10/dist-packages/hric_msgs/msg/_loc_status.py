# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:msg/LocStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LocStatus(type):
    """Metaclass of message 'LocStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'IDLE': 100,
        'INITIALIZING': 101,
        'RUNNING': 102,
        'WEAK': 103,
        'LOST': 104,
        'BLOCKED': 105,
        'NONE': 0,
        'UNKNOWN': 200,
        'TF_ERROR': 201,
        'SENSOR_ERROR': 202,
        'RELOCALIZATION_ERROR': 203,
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
                'hric_msgs.msg.LocStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__loc_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__loc_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__loc_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__loc_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__loc_status

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'IDLE': cls.__constants['IDLE'],
            'INITIALIZING': cls.__constants['INITIALIZING'],
            'RUNNING': cls.__constants['RUNNING'],
            'WEAK': cls.__constants['WEAK'],
            'LOST': cls.__constants['LOST'],
            'BLOCKED': cls.__constants['BLOCKED'],
            'NONE': cls.__constants['NONE'],
            'UNKNOWN': cls.__constants['UNKNOWN'],
            'TF_ERROR': cls.__constants['TF_ERROR'],
            'SENSOR_ERROR': cls.__constants['SENSOR_ERROR'],
            'RELOCALIZATION_ERROR': cls.__constants['RELOCALIZATION_ERROR'],
        }

    @property
    def IDLE(self):
        """Message constant 'IDLE'."""
        return Metaclass_LocStatus.__constants['IDLE']

    @property
    def INITIALIZING(self):
        """Message constant 'INITIALIZING'."""
        return Metaclass_LocStatus.__constants['INITIALIZING']

    @property
    def RUNNING(self):
        """Message constant 'RUNNING'."""
        return Metaclass_LocStatus.__constants['RUNNING']

    @property
    def WEAK(self):
        """Message constant 'WEAK'."""
        return Metaclass_LocStatus.__constants['WEAK']

    @property
    def LOST(self):
        """Message constant 'LOST'."""
        return Metaclass_LocStatus.__constants['LOST']

    @property
    def BLOCKED(self):
        """Message constant 'BLOCKED'."""
        return Metaclass_LocStatus.__constants['BLOCKED']

    @property
    def NONE(self):
        """Message constant 'NONE'."""
        return Metaclass_LocStatus.__constants['NONE']

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_LocStatus.__constants['UNKNOWN']

    @property
    def TF_ERROR(self):
        """Message constant 'TF_ERROR'."""
        return Metaclass_LocStatus.__constants['TF_ERROR']

    @property
    def SENSOR_ERROR(self):
        """Message constant 'SENSOR_ERROR'."""
        return Metaclass_LocStatus.__constants['SENSOR_ERROR']

    @property
    def RELOCALIZATION_ERROR(self):
        """Message constant 'RELOCALIZATION_ERROR'."""
        return Metaclass_LocStatus.__constants['RELOCALIZATION_ERROR']


class LocStatus(metaclass=Metaclass_LocStatus):
    """
    Message class 'LocStatus'.

    Constants:
      IDLE
      INITIALIZING
      RUNNING
      WEAK
      LOST
      BLOCKED
      NONE
      UNKNOWN
      TF_ERROR
      SENSOR_ERROR
      RELOCALIZATION_ERROR
    """

    __slots__ = [
        '_status',
        '_confidence',
        '_error_code',
        '_pose',
    ]

    _fields_and_field_types = {
        'status': 'uint8',
        'confidence': 'double',
        'error_code': 'uint32',
        'pose': 'geometry_msgs/PoseStamped',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        self.confidence = kwargs.get('confidence', float())
        self.error_code = kwargs.get('error_code', int())
        from geometry_msgs.msg import PoseStamped
        self.pose = kwargs.get('pose', PoseStamped())

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
        if self.confidence != other.confidence:
            return False
        if self.error_code != other.error_code:
            return False
        if self.pose != other.pose:
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
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'confidence' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._confidence = value

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

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'pose' field must be a sub message of type 'PoseStamped'"
        self._pose = value
