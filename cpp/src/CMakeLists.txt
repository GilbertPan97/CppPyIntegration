
# Find Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)
# message("Python_INCLUDE_DIRS: ${Python_INCLUDE_DIRS}")
# message("Python_LIBRARY_DIRS: ${Python_LIBRARY_DIRS}")
# message("Python_LIBRARIES: ${Python_LIBRARIES}")

# Import pybind11
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/venv/Lib/site-packages/pybind11/share/cmake/pybind11")
find_package(pybind11 REQUIRED)

# Include header file directories
include_directories(include)

# Create pybind11 module
pybind11_add_module(BinderLib MODULE binder.cpp binder_lib.cpp)

# Link Python library and pybind11 module
if(WIN32)
    # Set Python library based on project configuration
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        target_link_libraries(BinderLib PRIVATE ${Python_LIBRARY_DIRS}/python37_d.lib)
    else()
        target_link_libraries(BinderLib PRIVATE ${Python_LIBRARY_DIRS}/python37.lib)
    endif()
endif()

target_link_libraries(BinderLib PRIVATE pybind11::module Python::Module)

# Get Python::Module linked libraries
get_target_property(PYTHON_MODULE_LIBRARIES Python::Module INTERFACE_LINK_LIBRARIES)
message("Python::Module linked libraries: ${PYTHON_MODULE_LIBRARIES}")

set_target_properties(BinderLib PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF)


