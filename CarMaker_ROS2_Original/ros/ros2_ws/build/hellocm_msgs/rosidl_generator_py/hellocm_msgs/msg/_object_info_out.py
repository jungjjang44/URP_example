# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hellocm_msgs:msg/ObjectInfoOut.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'id'
# Member 'x'
# Member 'y'
# Member 'w'
# Member 'h'
# Member 'vx'
# Member 'vy'
# Member 'alpha'
# Member 'global_vx'
# Member 'global_vy'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ObjectInfoOut(type):
    """Metaclass of message 'ObjectInfoOut'."""

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
            module = import_type_support('hellocm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hellocm_msgs.msg.ObjectInfoOut')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__object_info_out
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__object_info_out
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__object_info_out
            cls._TYPE_SUPPORT = module.type_support_msg__msg__object_info_out
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__object_info_out

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObjectInfoOut(metaclass=Metaclass_ObjectInfoOut):
    """Message class 'ObjectInfoOut'."""

    __slots__ = [
        '_header',
        '_time',
        '_cycleno',
        '_synthdelay',
        '_num',
        '_id',
        '_x',
        '_y',
        '_w',
        '_h',
        '_vx',
        '_vy',
        '_alpha',
        '_global_vx',
        '_global_vy',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'time': 'builtin_interfaces/Time',
        'cycleno': 'int64',
        'synthdelay': 'double',
        'num': 'int16',
        'id': 'double[50]',
        'x': 'double[50]',
        'y': 'double[50]',
        'w': 'double[50]',
        'h': 'double[50]',
        'vx': 'double[50]',
        'vy': 'double[50]',
        'alpha': 'double[50]',
        'global_vx': 'double[50]',
        'global_vy': 'double[50]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 50),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from builtin_interfaces.msg import Time
        self.time = kwargs.get('time', Time())
        self.cycleno = kwargs.get('cycleno', int())
        self.synthdelay = kwargs.get('synthdelay', float())
        self.num = kwargs.get('num', int())
        if 'id' not in kwargs:
            self.id = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.id = numpy.array(kwargs.get('id'), dtype=numpy.float64)
            assert self.id.shape == (50, )
        if 'x' not in kwargs:
            self.x = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.x = numpy.array(kwargs.get('x'), dtype=numpy.float64)
            assert self.x.shape == (50, )
        if 'y' not in kwargs:
            self.y = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.y = numpy.array(kwargs.get('y'), dtype=numpy.float64)
            assert self.y.shape == (50, )
        if 'w' not in kwargs:
            self.w = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.w = numpy.array(kwargs.get('w'), dtype=numpy.float64)
            assert self.w.shape == (50, )
        if 'h' not in kwargs:
            self.h = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.h = numpy.array(kwargs.get('h'), dtype=numpy.float64)
            assert self.h.shape == (50, )
        if 'vx' not in kwargs:
            self.vx = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.vx = numpy.array(kwargs.get('vx'), dtype=numpy.float64)
            assert self.vx.shape == (50, )
        if 'vy' not in kwargs:
            self.vy = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.vy = numpy.array(kwargs.get('vy'), dtype=numpy.float64)
            assert self.vy.shape == (50, )
        if 'alpha' not in kwargs:
            self.alpha = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.alpha = numpy.array(kwargs.get('alpha'), dtype=numpy.float64)
            assert self.alpha.shape == (50, )
        if 'global_vx' not in kwargs:
            self.global_vx = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.global_vx = numpy.array(kwargs.get('global_vx'), dtype=numpy.float64)
            assert self.global_vx.shape == (50, )
        if 'global_vy' not in kwargs:
            self.global_vy = numpy.zeros(50, dtype=numpy.float64)
        else:
            self.global_vy = numpy.array(kwargs.get('global_vy'), dtype=numpy.float64)
            assert self.global_vy.shape == (50, )

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
        if self.header != other.header:
            return False
        if self.time != other.time:
            return False
        if self.cycleno != other.cycleno:
            return False
        if self.synthdelay != other.synthdelay:
            return False
        if self.num != other.num:
            return False
        if all(self.id != other.id):
            return False
        if all(self.x != other.x):
            return False
        if all(self.y != other.y):
            return False
        if all(self.w != other.w):
            return False
        if all(self.h != other.h):
            return False
        if all(self.vx != other.vx):
            return False
        if all(self.vy != other.vy):
            return False
        if all(self.alpha != other.alpha):
            return False
        if all(self.global_vx != other.global_vx):
            return False
        if all(self.global_vy != other.global_vy):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def time(self):
        """Message field 'time'."""
        return self._time

    @time.setter
    def time(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'time' field must be a sub message of type 'Time'"
        self._time = value

    @property
    def cycleno(self):
        """Message field 'cycleno'."""
        return self._cycleno

    @cycleno.setter
    def cycleno(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cycleno' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'cycleno' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._cycleno = value

    @property
    def synthdelay(self):
        """Message field 'synthdelay'."""
        return self._synthdelay

    @synthdelay.setter
    def synthdelay(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'synthdelay' field must be of type 'float'"
        self._synthdelay = value

    @property
    def num(self):
        """Message field 'num'."""
        return self._num

    @num.setter
    def num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'num' field must be an integer in [-32768, 32767]"
        self._num = value

    @property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'id' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'id' numpy.ndarray() must have a size of 50"
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'id' field must be a set or sequence with length 50 and each value of type 'float'"
        self._id = numpy.array(value, dtype=numpy.float64)

    @property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'x' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'x' numpy.ndarray() must have a size of 50"
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'x' field must be a set or sequence with length 50 and each value of type 'float'"
        self._x = numpy.array(value, dtype=numpy.float64)

    @property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'y' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'y' numpy.ndarray() must have a size of 50"
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'y' field must be a set or sequence with length 50 and each value of type 'float'"
        self._y = numpy.array(value, dtype=numpy.float64)

    @property
    def w(self):
        """Message field 'w'."""
        return self._w

    @w.setter
    def w(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'w' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'w' numpy.ndarray() must have a size of 50"
            self._w = value
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'w' field must be a set or sequence with length 50 and each value of type 'float'"
        self._w = numpy.array(value, dtype=numpy.float64)

    @property
    def h(self):
        """Message field 'h'."""
        return self._h

    @h.setter
    def h(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'h' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'h' numpy.ndarray() must have a size of 50"
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'h' field must be a set or sequence with length 50 and each value of type 'float'"
        self._h = numpy.array(value, dtype=numpy.float64)

    @property
    def vx(self):
        """Message field 'vx'."""
        return self._vx

    @vx.setter
    def vx(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'vx' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'vx' numpy.ndarray() must have a size of 50"
            self._vx = value
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'vx' field must be a set or sequence with length 50 and each value of type 'float'"
        self._vx = numpy.array(value, dtype=numpy.float64)

    @property
    def vy(self):
        """Message field 'vy'."""
        return self._vy

    @vy.setter
    def vy(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'vy' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'vy' numpy.ndarray() must have a size of 50"
            self._vy = value
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'vy' field must be a set or sequence with length 50 and each value of type 'float'"
        self._vy = numpy.array(value, dtype=numpy.float64)

    @property
    def alpha(self):
        """Message field 'alpha'."""
        return self._alpha

    @alpha.setter
    def alpha(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'alpha' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'alpha' numpy.ndarray() must have a size of 50"
            self._alpha = value
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'alpha' field must be a set or sequence with length 50 and each value of type 'float'"
        self._alpha = numpy.array(value, dtype=numpy.float64)

    @property
    def global_vx(self):
        """Message field 'global_vx'."""
        return self._global_vx

    @global_vx.setter
    def global_vx(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'global_vx' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'global_vx' numpy.ndarray() must have a size of 50"
            self._global_vx = value
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'global_vx' field must be a set or sequence with length 50 and each value of type 'float'"
        self._global_vx = numpy.array(value, dtype=numpy.float64)

    @property
    def global_vy(self):
        """Message field 'global_vy'."""
        return self._global_vy

    @global_vy.setter
    def global_vy(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'global_vy' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 50, \
                "The 'global_vy' numpy.ndarray() must have a size of 50"
            self._global_vy = value
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
                 len(value) == 50 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'global_vy' field must be a set or sequence with length 50 and each value of type 'float'"
        self._global_vy = numpy.array(value, dtype=numpy.float64)
