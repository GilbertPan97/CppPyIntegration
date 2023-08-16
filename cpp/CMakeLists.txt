
if(NOT THIRD_PARTY)
    set(THIRD_PARTY ${CMAKE_SOURCE_DIR}/3rd-party)
    if(NOT EXISTS ${THIRD_PARTY})
        message(FATAL_ERROR "Third party directory is not exist.")
    endif()
endif()

add_subdirectory(src)

# add exec program
add_executable(py_subprocess py_subprocess.cpp)

# find and link nlohmann_json package
find_package(nlohmann_json REQUIRED HINTS ${THIRD_PARTY}/json-3.11.2/share/cmake)
target_link_libraries(py_subprocess PRIVATE nlohmann_json::nlohmann_json)

# find and link glog package
find_package(glog REQUIRED HINTS ${THIRD_PARTY})
target_link_libraries(py_subprocess PRIVATE glog::glog)

# set target property to build pyCallCppApp
set_target_properties(py_subprocess PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF)