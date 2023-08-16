// binder.cpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "binder_lib.h"

namespace py = pybind11;

PYBIND11_MODULE(BinderLib, m) {
    py::class_<BinderLib>(m, "BinderLib")
        .def(py::init())
        .def("capture_photo", &BinderLib::capturePhoto)
        .def("process_image", &BinderLib::processImage);
}