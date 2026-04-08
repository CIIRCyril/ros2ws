# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:srv/UpdateMarker.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UpdateMarker_Request(type):
    """Metaclass of message 'UpdateMarker_Request'."""

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
                'hric_msgs.srv.UpdateMarker_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__update_marker__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__update_marker__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__update_marker__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__update_marker__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__update_marker__request

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


class UpdateMarker_Request(metaclass=Metaclass_UpdateMarker_Request):
    """Message class 'UpdateMarker_Request'."""

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


class Metaclass_UpdateMarker_Response(type):
    """Metaclass of message 'UpdateMarker_Response'."""

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
                'hric_msgs.srv.UpdateMarker_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__update_marker__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__update_marker__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__update_marker__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__update_marker__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__update_marker__response

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


class UpdateMarker_Response(metaclass=Metaclass_UpdateMarker_Response):
    """Message class 'UpdateMarker_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_marker_old',
        '_marker_new',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'marker_old': 'hric_msgs/MarkerInfo',
        'marker_new': 'hric_msgs/MarkerInfo',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hric_msgs', 'msg'], 'MarkerInfo'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hric_msgs', 'msg'], 'MarkerInfo'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        from hric_msgs.msg import MarkerInfo
        self.marker_old = kwargs.get('marker_old', MarkerInfo())
        from hric_msgs.msg import MarkerInfo
        self.marker_new = kwargs.get('marker_new', MarkerInfo())

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
        if self.marker_old != other.marker_old:
            return False
        if self.marker_new != other.marker_new:
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
    def marker_old(self):
        """Message field 'marker_old'."""
        return self._marker_old

    @marker_old.setter
    def marker_old(self, value):
        if __debug__:
            from hric_msgs.msg import MarkerInfo
            assert \
                isinstance(value, MarkerInfo), \
                "The 'marker_old' field must be a sub message of type 'MarkerInfo'"
        self._marker_old = value

    @builtins.property
    def marker_new(self):
        """Message field 'marker_new'."""
        return self._marker_new

    @marker_new.setter
    def marker_new(self, value):
        if __debug__:
            from hric_msgs.msg import MarkerInfo
            assert \
                isinstance(value, MarkerInfo), \
                "The 'marker_new' field must be a sub message of type 'MarkerInfo'"
        self._marker_new = value


class Metaclass_UpdateMarker(type):
    """Metaclass of service 'UpdateMarker'."""

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
                'hric_msgs.srv.UpdateMarker')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__update_marker

            from hric_msgs.srv import _update_marker
            if _update_marker.Metaclass_UpdateMarker_Request._TYPE_SUPPORT is None:
                _update_marker.Metaclass_UpdateMarker_Request.__import_type_support__()
            if _update_marker.Metaclass_UpdateMarker_Response._TYPE_SUPPORT is None:
                _update_marker.Metaclass_UpdateMarker_Response.__import_type_support__()


class UpdateMarker(metaclass=Metaclass_UpdateMarker):
    from hric_msgs.srv._update_marker import UpdateMarker_Request as Request
    from hric_msgs.srv._update_marker import UpdateMarker_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
