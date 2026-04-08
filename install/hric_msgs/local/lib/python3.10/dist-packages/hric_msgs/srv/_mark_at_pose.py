# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:srv/MarkAtPose.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MarkAtPose_Request(type):
    """Metaclass of message 'MarkAtPose_Request'."""

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
            module = import_type_support('hric_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hric_msgs.srv.MarkAtPose_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__mark_at_pose__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__mark_at_pose__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__mark_at_pose__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__mark_at_pose__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__mark_at_pose__request

            from geometry_msgs.msg import Pose2D
            if Pose2D.__class__._TYPE_SUPPORT is None:
                Pose2D.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarkAtPose_Request(metaclass=Metaclass_MarkAtPose_Request):
    """Message class 'MarkAtPose_Request'."""

    __slots__ = [
        '_name',
        '_map_id',
        '_floor',
        '_pose',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'map_id': 'string',
        'floor': 'string',
        'pose': 'geometry_msgs/Pose2D',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose2D'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.map_id = kwargs.get('map_id', str())
        self.floor = kwargs.get('floor', str())
        from geometry_msgs.msg import Pose2D
        self.pose = kwargs.get('pose', Pose2D())

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
        if self.name != other.name:
            return False
        if self.map_id != other.map_id:
            return False
        if self.floor != other.floor:
            return False
        if self.pose != other.pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def map_id(self):
        """Message field 'map_id'."""
        return self._map_id

    @map_id.setter
    def map_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'map_id' field must be of type 'str'"
        self._map_id = value

    @builtins.property
    def floor(self):
        """Message field 'floor'."""
        return self._floor

    @floor.setter
    def floor(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'floor' field must be of type 'str'"
        self._floor = value

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose2D
            assert \
                isinstance(value, Pose2D), \
                "The 'pose' field must be a sub message of type 'Pose2D'"
        self._pose = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MarkAtPose_Response(type):
    """Metaclass of message 'MarkAtPose_Response'."""

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
            module = import_type_support('hric_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hric_msgs.srv.MarkAtPose_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__mark_at_pose__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__mark_at_pose__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__mark_at_pose__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__mark_at_pose__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__mark_at_pose__response

            from hric_msgs.msg import MarkerInfo
            if MarkerInfo.__class__._TYPE_SUPPORT is None:
                MarkerInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarkAtPose_Response(metaclass=Metaclass_MarkAtPose_Response):
    """Message class 'MarkAtPose_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_marker',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'marker': 'hric_msgs/MarkerInfo',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hric_msgs', 'msg'], 'MarkerInfo'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        from hric_msgs.msg import MarkerInfo
        self.marker = kwargs.get('marker', MarkerInfo())

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
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.marker != other.marker:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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

    @builtins.property
    def marker(self):
        """Message field 'marker'."""
        return self._marker

    @marker.setter
    def marker(self, value):
        if __debug__:
            from hric_msgs.msg import MarkerInfo
            assert \
                isinstance(value, MarkerInfo), \
                "The 'marker' field must be a sub message of type 'MarkerInfo'"
        self._marker = value


class Metaclass_MarkAtPose(type):
    """Metaclass of service 'MarkAtPose'."""

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
                'hric_msgs.srv.MarkAtPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__mark_at_pose

            from hric_msgs.srv import _mark_at_pose
            if _mark_at_pose.Metaclass_MarkAtPose_Request._TYPE_SUPPORT is None:
                _mark_at_pose.Metaclass_MarkAtPose_Request.__import_type_support__()
            if _mark_at_pose.Metaclass_MarkAtPose_Response._TYPE_SUPPORT is None:
                _mark_at_pose.Metaclass_MarkAtPose_Response.__import_type_support__()


class MarkAtPose(metaclass=Metaclass_MarkAtPose):
    from hric_msgs.srv._mark_at_pose import MarkAtPose_Request as Request
    from hric_msgs.srv._mark_at_pose import MarkAtPose_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
