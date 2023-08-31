# Define a macro to handle subdirectories
macro(add_subdirectory_with_clean_variables _dir)
    # Set up an isolated build environment here
    set(_tmp_cmake_args "${CMAKE_COMMAND}" "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
    execute_process(COMMAND ${_tmp_cmake_args} "${_dir}" WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${_dir}")

    # Add the subdirectory
    add_subdirectory("${_dir}" "${CMAKE_BINARY_DIR}/${_dir}")
endmacro()