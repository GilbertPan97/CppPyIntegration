cmake_minimum_required(VERSION 3.12)
project(CppPyIntDemo)

set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party)

# add include file search dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
include(CppPyIntegrationUtils)

# build dependences
add_subdirectory(${THIRD_PARTY}/glog)
add_subdirectory(${THIRD_PARTY}/json)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif (NOT CMAKE_BUILD_TYPE)

# set project output dir and postfix
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "Adds a postfix for debug-built libraries")
set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "Adds a postfix for release-built libraries")
set(CMAKE_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "Adds a postfix for RelWithDebugInfo-built libraries")
set(CMAKE_MINSIZEREL_POSTFIX "_s" CACHE STRING "Adds a postfix for MinsizeRel-built libraries")

add_subdirectory(cpp)
add_subdirectory(examples)
