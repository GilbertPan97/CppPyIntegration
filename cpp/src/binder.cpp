// binder.cpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_lib.h"

namespace py = pybind11;

PYBIND11_MODULE(WrapperLib, m) {
    py::class_<WrapperLib>(m, "PyWrapperLib")
        .def(py::init())
        .def("capture_photo", &WrapperLib::capturePhoto)
        .def("process_image", &WrapperLib::processImage);
}