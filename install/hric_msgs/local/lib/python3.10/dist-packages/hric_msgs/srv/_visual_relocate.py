# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:srv/VisualRelocate.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VisualRelocate_Request(type):
    """Metaclass of message 'VisualRelocate_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'LOCAL_MATCH': 1,
        'GLOBAL_MATCH': 2,
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
                'hric_msgs.srv.VisualRelocate_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__visual_relocate__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__visual_relocate__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__visual_relocate__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__visual_relocate__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__visual_relocate__request

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'LOCAL_MATCH': cls.__constants['LOCAL_MATCH'],
            'GLOBAL_MATCH': cls.__constants['GLOBAL_MATCH'],
        }

    @property
    def LOCAL_MATCH(self):
        """Message constant 'LOCAL_MATCH'."""
        return Metaclass_VisualRelocate_Request.__constants['LOCAL_MATCH']

    @property
    def GLOBAL_MATCH(self):
        """Message constant 'GLOBAL_MATCH'."""
        return Metaclass_VisualRelocate_Request.__constants['GLOBAL_MATCH']


class VisualRelocate_Request(metaclass=Metaclass_VisualRelocate_Request):
    """
    Message class 'VisualRelocate_Request'.

    Constants:
      LOCAL_MATCH
      GLOBAL_MATCH
    """

    __slots__ = [
        '_pose_ref',
        '_match_type',
    ]

    _fields_and_field_types = {
        'pose_ref': 'geometry_msgs/PoseStamped',
        'match_type': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import PoseStamped
        self.pose_ref = kwargs.get('pose_ref', PoseStamped())
        self.match_type = kwargs.get('match_type', int())

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
        if self.pose_ref != other.pose_ref:
            return False
        if self.match_type != other.match_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pose_ref(self):
        """Message field 'pose_ref'."""
        return self._pose_ref

    @pose_ref.setter
    def pose_ref(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'pose_ref' field must be a sub message of type 'PoseStamped'"
        self._pose_ref = value

    @builtins.property
    def match_type(self):
        """Message field 'match_type'."""
        return self._match_type

    @match_type.setter
    def match_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'match_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'match_type' field must be an unsigned integer in [0, 255]"
        self._match_type = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_VisualRelocate_Response(type):
    """Metaclass of message 'VisualRelocate_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NONE': 0,
        'UNKNOWN': 200,
        'TF_ERROR': 201,
        'SENSOR_ERROR': 202,
        'LOW_CONFIDENCE': 203,
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
                'hric_msgs.srv.VisualRelocate_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__visual_relocate__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__visual_relocate__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__visual_relocate__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__visual_relocate__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__visual_relocate__response

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NONE': cls.__constants['NONE'],
            'UNKNOWN': cls.__constants['UNKNOWN'],
            'TF_ERROR': cls.__constants['TF_ERROR'],
            'SENSOR_ERROR': cls.__constants['SENSOR_ERROR'],
            'LOW_CONFIDENCE': cls.__constants['LOW_CONFIDENCE'],
        }

    @property
    def NONE(self):
        """Message constant 'NONE'."""
        return Metaclass_VisualRelocate_Response.__constants['NONE']

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_VisualRelocate_Response.__constants['UNKNOWN']

    @property
    def TF_ERROR(self):
        """Message constant 'TF_ERROR'."""
        return Metaclass_VisualRelocate_Response.__constants['TF_ERROR']

    @property
    def SENSOR_ERROR(self):
        """Message constant 'SENSOR_ERROR'."""
        return Metaclass_VisualRelocate_Response.__constants['SENSOR_ERROR']

    @property
    def LOW_CONFIDENCE(self):
        """Message constant 'LOW_CONFIDENCE'."""
        return Metaclass_VisualRelocate_Response.__constants['LOW_CONFIDENCE']


class VisualRelocate_Response(metaclass=Metaclass_VisualRelocate_Response):
    """
    Message class 'VisualRelocate_Response'.

    Constants:
      NONE
      UNKNOWN
      TF_ERROR
      SENSOR_ERROR
      LOW_CONFIDENCE
    """

    __slots__ = [
        '_pose_robot',
        '_success',
        '_error_code',
        '_message',
    ]

    _fields_and_field_types = {
        'pose_robot': 'geometry_msgs/PoseStamped',
        'success': 'boolean',
        'error_code': 'uint32',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import PoseStamped
        self.pose_robot = kwargs.get('pose_robot', PoseStamped())
        self.success = kwargs.get('success', bool())
        self.error_code = kwargs.get('error_code', int())
        self.message = kwargs.get('message', str())

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
        if self.pose_robot != other.pose_robot:
            return False
        if self.success != other.success:
            return False
        if self.error_code != other.error_code:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pose_robot(self):
        """Message field 'pose_robot'."""
        return self._pose_robot

    @pose_robot.setter
    def pose_robot(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'pose_robot' field must be a sub message of type 'PoseStamped'"
        self._pose_robot = value

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

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
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_VisualRelocate(type):
    """Metaclass of service 'VisualRelocate'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hric_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hric_msgs.srv.VisualRelocate')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__visual_relocate

            from hric_msgs.srv import _visual_relocate
            if _visual_relocate.Metaclass_VisualRelocate_Request._TYPE_SUPPORT is None:
                _visual_relocate.Metaclass_VisualRelocate_Request.__import_type_support__()
            if _visual_relocate.Metaclass_VisualRelocate_Response._TYPE_SUPPORT is None:
                _visual_relocate.Metaclass_VisualRelocate_Response.__import_type_support__()


class VisualRelocate(metaclass=Metaclass_VisualRelocate):
    from hric_msgs.srv._visual_relocate import VisualRelocate_Request as Request
    from hric_msgs.srv._visual_relocate import VisualRelocate_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
