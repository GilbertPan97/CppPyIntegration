
# cpp_call_python_main: Python.h used for python integrate in cpp
add_executable(cpp_call_python_main cpp_call_python_main.cpp)

# find and link Python3 package
find_package(Python3 COMPONENTS Development REQUIRED)
target_include_directories(cpp_call_python_main PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(cpp_call_python_main PRIVATE Python3::Python)

set_target_properties(cpp_call_python_main  PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF)