# math_wrapper.pxd
# 定义Cython扩展模块中需要导入的内容

cdef extern from "math_utils.h":
    cdef cppclass MathUtils:
        MathUtils()
        int add(int a, int b)
