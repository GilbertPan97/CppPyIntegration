# CppPyIntegration

CppPyIntegration is a project showcasing multiple integration approaches between C++ and Python programs. It offers examples for invoking C++ code from Python, encapsulating C++ code as a Python library, creating subprocesses for C++ execution, and invoking Python functions from C++. The project is structured to provide clarity and ease of navigation.

## Features

- Demonstrates four integration methods between C++ and Python:
  1. **Python Calls C++ through Binding**: Python code calls C++ functions directly using binding libraries.
  2. **C++ Code Wrapped as Python Library**: C++ code is wrapped and exposed as a Python module.
  3. **Python Spawns Subprocess for C++ Execution**: Python launches C++ programs as subprocesses with inter-process communication.
  4. **C++ Invokes Python Function**: C++ code embeds a Python interpreter to call Python functions.

## Directory Structure
```bash
CppPyIntegration/
│
├── CMakeLists.txt              # Root-level CMake configuration file
│
├── cpp/
│ ├── CMakeLists.txt            # C++ code CMake configuration file
│ ├── src/                      # C++ source code
│ └── your_cpp_code.cpp         
│
├── python/
│ └── cppCall.py     # Python module wrapping C++ code
│
├── examples/
│ ├── python_call_cpp_binding.py        # Example: Python calls C++ through binding
│ ├── python_import_cpp_library.py      # Example: C++ code wrapped as Python library
│ ├── python_spawn_subprocess.py        # Example: Python spawns subprocess for C++ execution
│ └── cpp_call_python_function.cpp      # Example: C++ invokes Python function
│
└── README.md                           # Project documentation

```


## Usage

Each integration method has its own example script within the `examples/` directory. Follow these steps to try them out:

1. **Python Calls C++ through Binding**:
   - Navigate to the `examples/` directory.
   - Run `python_call_cpp_binding.py` to see Python calling C++ through binding.

2. **C++ Code Wrapped as Python Library**:
   - Build the C++ library according to the instructions in the `cpp/` directory.
   - Import the `your_python_module` module from the `python/` directory in your Python code.

3. **Python Spawns Subprocess for C++ Execution**:
   - Run `python_spawn_subprocess.py` in the `examples/` directory to see Python creating a subprocess for C++ execution.

4. **C++ Invokes Python Function**:
   - Build the C++ program using the instructions in the `examples/` directory.
   - Run the compiled program to see C++ invoking a Python function.

## Installation and Building

To build and run the examples, follow these steps:

1. **Building C++ Code**:
   - Navigate to the `cpp/` directory.
   - Follow the instructions in `CMakeLists.txt` to build the C++ code.

2. **Running Examples**:
   - Navigate to the `examples/` directory.
   - Run the desired example script using Python or execute the compiled C++ program.

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to explore and adapt the integration methods to your specific needs!

For detailed instructions on each integration method, refer to the README files in their respective directories.

