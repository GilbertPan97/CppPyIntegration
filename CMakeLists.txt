cmake_minimum_required(VERSION 3.0)
project(CppPyIntDemo)

set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party)

# add include file search dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_DEBUG_POSTFIX "_Debug" CACHE STRING "Adds a postfix for debug-built libraries")
set(CMAKE_MINSIZEREL_POSTFIX "_MinsizeRel" CACHE STRING "Adds a postfix for MinsizeRel-built libraries")

add_subdirectory(cpp)
add_subdirectory(examples)
