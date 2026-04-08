# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:srv/SetVisualLocMode.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetVisualLocMode_Request(type):
    """Metaclass of message 'SetVisualLocMode_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'IDLE_MODE': 0,
        'ODOM_MODE': 1,
        'MAP_REFINE_MODE': 2,
        'MAP_LOC_MODE': 3,
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
                'hric_msgs.srv.SetVisualLocMode_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_visual_loc_mode__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_visual_loc_mode__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_visual_loc_mode__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_visual_loc_mode__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_visual_loc_mode__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'IDLE_MODE': cls.__constants['IDLE_MODE'],
            'ODOM_MODE': cls.__constants['ODOM_MODE'],
            'MAP_REFINE_MODE': cls.__constants['MAP_REFINE_MODE'],
            'MAP_LOC_MODE': cls.__constants['MAP_LOC_MODE'],
        }

    @property
    def IDLE_MODE(self):
        """Message constant 'IDLE_MODE'."""
        return Metaclass_SetVisualLocMode_Request.__constants['IDLE_MODE']

    @property
    def ODOM_MODE(self):
        """Message constant 'ODOM_MODE'."""
        return Metaclass_SetVisualLocMode_Request.__constants['ODOM_MODE']

    @property
    def MAP_REFINE_MODE(self):
        """Message constant 'MAP_REFINE_MODE'."""
        return Metaclass_SetVisualLocMode_Request.__constants['MAP_REFINE_MODE']

    @property
    def MAP_LOC_MODE(self):
        """Message constant 'MAP_LOC_MODE'."""
        return Metaclass_SetVisualLocMode_Request.__constants['MAP_LOC_MODE']


class SetVisualLocMode_Request(metaclass=Metaclass_SetVisualLocMode_Request):
    """
    Message class 'SetVisualLocMode_Request'.

    Constants:
      IDLE_MODE
      ODOM_MODE
      MAP_REFINE_MODE
      MAP_LOC_MODE
    """

    __slots__ = [
        '_loc_mode',
    ]

    _fields_and_field_types = {
        'loc_mode': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.loc_mode = kwargs.get('loc_mode', int())

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
        if self.loc_mode != other.loc_mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def loc_mode(self):
        """Message field 'loc_mode'."""
        return self._loc_mode

    @loc_mode.setter
    def loc_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'loc_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'loc_mode' field must be an unsigned integer in [0, 255]"
        self._loc_mode = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetVisualLocMode_Response(type):
    """Metaclass of message 'SetVisualLocMode_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NONE': 0,
        'UNKNOWN': 200,
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
                'hric_msgs.srv.SetVisualLocMode_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_visual_loc_mode__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_visual_loc_mode__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_visual_loc_mode__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_visual_loc_mode__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_visual_loc_mode__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NONE': cls.__constants['NONE'],
            'UNKNOWN': cls.__constants['UNKNOWN'],
        }

    @property
    def NONE(self):
        """Message constant 'NONE'."""
        return Metaclass_SetVisualLocMode_Response.__constants['NONE']

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_SetVisualLocMode_Response.__constants['UNKNOWN']


class SetVisualLocMode_Response(metaclass=Metaclass_SetVisualLocMode_Response):
    """
    Message class 'SetVisualLocMode_Response'.

    Constants:
      NONE
      UNKNOWN
    """

    __slots__ = [
        '_success',
        '_error_code',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'error_code': 'uint32',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
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


class Metaclass_SetVisualLocMode(type):
    """Metaclass of service 'SetVisualLocMode'."""

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
                'hric_msgs.srv.SetVisualLocMode')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_visual_loc_mode

            from hric_msgs.srv import _set_visual_loc_mode
            if _set_visual_loc_mode.Metaclass_SetVisualLocMode_Request._TYPE_SUPPORT is None:
                _set_visual_loc_mode.Metaclass_SetVisualLocMode_Request.__import_type_support__()
            if _set_visual_loc_mode.Metaclass_SetVisualLocMode_Response._TYPE_SUPPORT is None:
                _set_visual_loc_mode.Metaclass_SetVisualLocMode_Response.__import_type_support__()


class SetVisualLocMode(metaclass=Metaclass_SetVisualLocMode):
    from hric_msgs.srv._set_visual_loc_mode import SetVisualLocMode_Request as Request
    from hric_msgs.srv._set_visual_loc_mode import SetVisualLocMode_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
