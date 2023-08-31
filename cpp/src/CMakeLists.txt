# Find Python
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
# message("Python_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
# message("Python_LIBRARY_DIRS: ${Python3_LIBRARY_DIRS}")
# message("Python_LIBRARIES: ${Python3_LIBRARIES}")

# Import pybind11
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/venv/Lib/site-packages/pybind11/share/cmake/pybind11")
find_package(pybind11 REQUIRED)

# Include header file directories
include_directories(include)

# Create pybind11 module
pybind11_add_module(WrapperLib MODULE binder.cpp wrapper_lib.cpp)

# # Link Python library and pybind11 module
# set(CMAKE_BUILD_TYPE Debug)
# if(WIN32)
#     # Set Python library based on project configuration
#     if(CMAKE_BUILD_TYPE MATCHES Debug)
#         target_link_libraries(WrapperLib PRIVATE ${Python3_LIBRARY_DIRS}/python37_d.lib)
#     else()
#         target_link_libraries(WrapperLib PRIVATE ${Python3_LIBRARY_DIRS}/python37.lib)
#     endif()
# endif()

target_link_libraries(WrapperLib PRIVATE pybind11::module Python3::Module)

# # Get Python::Module linked libraries
# get_target_property(PYTHON_MODULE_LIBRARIES Python3::Module INTERFACE_LINK_LIBRARIES)
# message("Python::Module linked libraries: ${PYTHON_MODULE_LIBRARIES}")

set_target_properties(WrapperLib PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF)

# copy build python package to example directory
add_custom_command(TARGET WrapperLib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:WrapperLib>
        ${CMAKE_SOURCE_DIR}/examples/utils
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE_DIR:WrapperLib>/WrapperLib.lib
        ${CMAKE_SOURCE_DIR}/examples/utils
    COMMENT "Copying executable if different after build"
)
