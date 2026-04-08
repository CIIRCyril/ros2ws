# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hric_msgs:srv/SetMotionMode.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetMotionMode_Request(type):
    """Metaclass of message 'SetMotionMode_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'START': 0,
        'STOP': 1,
        'ZERO': 2,
        'STAND': 3,
        'WALK': 4,
        'RUN': 5,
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
                'hric_msgs.srv.SetMotionMode_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_motion_mode__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_motion_mode__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_motion_mode__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_motion_mode__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_motion_mode__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'START': cls.__constants['START'],
            'STOP': cls.__constants['STOP'],
            'ZERO': cls.__constants['ZERO'],
            'STAND': cls.__constants['STAND'],
            'WALK': cls.__constants['WALK'],
            'RUN': cls.__constants['RUN'],
        }

    @property
    def START(self):
        """Message constant 'START'."""
        return Metaclass_SetMotionMode_Request.__constants['START']

    @property
    def STOP(self):
        """Message constant 'STOP'."""
        return Metaclass_SetMotionMode_Request.__constants['STOP']

    @property
    def ZERO(self):
        """Message constant 'ZERO'."""
        return Metaclass_SetMotionMode_Request.__constants['ZERO']

    @property
    def STAND(self):
        """Message constant 'STAND'."""
        return Metaclass_SetMotionMode_Request.__constants['STAND']

    @property
    def WALK(self):
        """Message constant 'WALK'."""
        return Metaclass_SetMotionMode_Request.__constants['WALK']

    @property
    def RUN(self):
        """Message constant 'RUN'."""
        return Metaclass_SetMotionMode_Request.__constants['RUN']


class SetMotionMode_Request(metaclass=Metaclass_SetMotionMode_Request):
    """
    Message class 'SetMotionMode_Request'.

    Constants:
      START
      STOP
      ZERO
      STAND
      WALK
      RUN
    """

    __slots__ = [
        '_walk_mode_request',
        '_is_need_swing_arm',
    ]

    _fields_and_field_types = {
        'walk_mode_request': 'uint8',
        'is_need_swing_arm': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.walk_mode_request = kwargs.get('walk_mode_request', int())
        self.is_need_swing_arm = kwargs.get('is_need_swing_arm', bool())

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
        if self.walk_mode_request != other.walk_mode_request:
            return False
        if self.is_need_swing_arm != other.is_need_swing_arm:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def walk_mode_request(self):
        """Message field 'walk_mode_request'."""
        return self._walk_mode_request

    @walk_mode_request.setter
    def walk_mode_request(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'walk_mode_request' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'walk_mode_request' field must be an unsigned integer in [0, 255]"
        self._walk_mode_request = value

    @builtins.property
    def is_need_swing_arm(self):
        """Message field 'is_need_swing_arm'."""
        return self._is_need_swing_arm

    @is_need_swing_arm.setter
    def is_need_swing_arm(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_need_swing_arm' field must be of type 'bool'"
        self._is_need_swing_arm = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetMotionMode_Response(type):
    """Metaclass of message 'SetMotionMode_Response'."""

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
                'hric_msgs.srv.SetMotionMode_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_motion_mode__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_motion_mode__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_motion_mode__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_motion_mode__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_motion_mode__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetMotionMode_Response(metaclass=Metaclass_SetMotionMode_Response):
    """Message class 'SetMotionMode_Response'."""

    __slots__ = [
        '_success',
        '_error_code',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'error_code': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
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
        if self.success != other.success:
            return False
        if self.error_code != other.error_code:
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


class Metaclass_SetMotionMode(type):
    """Metaclass of service 'SetMotionMode'."""

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
                'hric_msgs.srv.SetMotionMode')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_motion_mode

            from hric_msgs.srv import _set_motion_mode
            if _set_motion_mode.Metaclass_SetMotionMode_Request._TYPE_SUPPORT is None:
                _set_motion_mode.Metaclass_SetMotionMode_Request.__import_type_support__()
            if _set_motion_mode.Metaclass_SetMotionMode_Response._TYPE_SUPPORT is None:
                _set_motion_mode.Metaclass_SetMotionMode_Response.__import_type_support__()


class SetMotionMode(metaclass=Metaclass_SetMotionMode):
    from hric_msgs.srv._set_motion_mode import SetMotionMode_Request as Request
    from hric_msgs.srv._set_motion_mode import SetMotionMode_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
