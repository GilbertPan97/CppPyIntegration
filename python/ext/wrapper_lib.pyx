# wrapper_lib.pyx

# cimport wrapper_lib

import cython
from libcpp.vector cimport vector
from libcpp.utility cimport pair

cdef extern from "wrapper_lib.h":
    cdef cppclass WrapperLib:
        WrapperLib()
        void capturePhoto()
        pair[int, vector[float]] processImage()


# Define Python interface for using the C++ library in Python
cdef class PyWrapperLib:
    cdef WrapperLib cpp_wrapper_lib     # Hold a C++ instance which we're wrapping

    def __init__(self):
        self.cpp_wrapper_lib = WrapperLib()

    def capture_photo(self):
        self.cpp_wrapper_lib.capturePhoto()

    def process_image(self):
        print("Convert C++ std::pair to Python tuple")
        cdef pair[int, vector[float]] cpp_result = self.cpp_wrapper_lib.processImage()
        cdef tuple[int, list[float]] py_result = (cpp_result.first, list(cpp_result.second))

        return py_result
