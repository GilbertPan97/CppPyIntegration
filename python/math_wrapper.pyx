# math_wrapper.pyx

cimport math_wrapper

# 定义Python接口，以便在Python中使用C++类
cdef class PyMathUtils:
    cdef math_wrapper.MathUtils *cpp_math_utils
    
    def __cinit__(self):
        self.cpp_math_utils = new math_wrapper.MathUtils()
    
    def add(self, int a, int b):
        return self.cpp_math_utils.add(a, b)
