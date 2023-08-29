# wrapper_lib.pxd
# Define the necessary imports in a Cython extension module

cdef extern from "wrapper_lib.h":
    cdef cppclass WrapperLib:
        WrapperLib()
        void capturePhoto()
#         std::pair[int, std::vector[float]] processImage()
#         ctypedef tuple[int, list[float]] processImage()
