# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/Paths.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'x'
# Member 'y'
# Member 's'
# Member 'h'
# Member 'id'
# Member 'left_roi'
# Member 'right_roi'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Paths(type):
    """Metaclass of message 'Paths'."""

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
            module = import_type_support('custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msgs.msg.Paths')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__paths
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__paths
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__paths
            cls._TYPE_SUPPORT = module.type_support_msg__msg__paths
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__paths

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Paths(metaclass=Metaclass_Paths):
    """Message class 'Paths'."""

    __slots__ = [
        '_x',
        '_y',
        '_s',
        '_h',
        '_id',
        '_left_roi',
        '_right_roi',
    ]

    _fields_and_field_types = {
        'x': 'sequence<double>',
        'y': 'sequence<double>',
        's': 'sequence<double>',
        'h': 'sequence<double>',
        'id': 'sequence<double>',
        'left_roi': 'sequence<float>',
        'right_roi': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = array.array('d', kwargs.get('x', []))
        self.y = array.array('d', kwargs.get('y', []))
        self.s = array.array('d', kwargs.get('s', []))
        self.h = array.array('d', kwargs.get('h', []))
        self.id = array.array('d', kwargs.get('id', []))
        self.left_roi = array.array('f', kwargs.get('left_roi', []))
        self.right_roi = array.array('f', kwargs.get('right_roi', []))

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
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.s != other.s:
            return False
        if self.h != other.h:
            return False
        if self.id != other.id:
            return False
        if self.left_roi != other.left_roi:
            return False
        if self.right_roi != other.right_roi:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'x' array.array() must have the type code of 'd'"
            self._x = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'x' field must be a set or sequence and each value of type 'float'"
        self._x = array.array('d', value)

    @property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'y' array.array() must have the type code of 'd'"
            self._y = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'y' field must be a set or sequence and each value of type 'float'"
        self._y = array.array('d', value)

    @property
    def s(self):
        """Message field 's'."""
        return self._s

    @s.setter
    def s(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 's' array.array() must have the type code of 'd'"
            self._s = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 's' field must be a set or sequence and each value of type 'float'"
        self._s = array.array('d', value)

    @property
    def h(self):
        """Message field 'h'."""
        return self._h

    @h.setter
    def h(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'h' array.array() must have the type code of 'd'"
            self._h = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'h' field must be a set or sequence and each value of type 'float'"
        self._h = array.array('d', value)

    @property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'id' array.array() must have the type code of 'd'"
            self._id = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'id' field must be a set or sequence and each value of type 'float'"
        self._id = array.array('d', value)

    @property
    def left_roi(self):
        """Message field 'left_roi'."""
        return self._left_roi

    @left_roi.setter
    def left_roi(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'left_roi' array.array() must have the type code of 'f'"
            self._left_roi = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'left_roi' field must be a set or sequence and each value of type 'float'"
        self._left_roi = array.array('f', value)

    @property
    def right_roi(self):
        """Message field 'right_roi'."""
        return self._right_roi

    @right_roi.setter
    def right_roi(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'right_roi' array.array() must have the type code of 'f'"
            self._right_roi = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'right_roi' field must be a set or sequence and each value of type 'float'"
        self._right_roi = array.array('f', value)
