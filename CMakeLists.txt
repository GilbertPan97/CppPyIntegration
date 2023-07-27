cmake_minimum_required(VERSION 3.0)
project(CppPyIntDemo)

set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party)
set(OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# add include file search dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


# =========================================================================================== #
# ====== used for "demoMain.py" (Python) to call "pyCall.cpp" (C++) and execute a task ====== #
# =========================================================================================== #
# add exec program
add_executable(pyCallCppApp pyCall.cpp)

# find and link nlohmann_json package
find_package(nlohmann_json REQUIRED HINTS ${THIRD_PARTY}/json-3.11.2/share/cmake)
target_link_libraries(pyCallCppApp PRIVATE nlohmann_json::nlohmann_json)

# find and link glog package
find_package(glog REQUIRED HINTS ${THIRD_PARTY})
target_link_libraries(pyCallCppApp PRIVATE glog::glog)

# set target property to build pyCallCppApp
set_target_properties(pyCallCppApp PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF
                      ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
                      LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
                      RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")


# =========================================================================================== #
# ===== used for "demoMain.cpp" (C++) to call "cppCall.py" (Python) and execute a task ====== #
# =========================================================================================== #
# add exec program
add_executable(cppCallPyApp demoMain.cpp)

# find and link Python3 package
find_package(Python3 COMPONENTS Development REQUIRED)
target_include_directories(cppCallPyApp PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(cppCallPyApp PRIVATE Python3::Python)

set_target_properties(cppCallPyApp  PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF
                      ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
                      LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
                      RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
