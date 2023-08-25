# CppPyIntegration

CppPyIntegration is a project that showcases various integration methods between C++ and Python programs. It offers examples of invoking C++ code from Python as well as calling Python functions from C++. These integration techniques include encapsulating C++ code as a Python library and creating subprocesses for C++ execution. The project's architecture is designed to provide clear and reproducible functionalities, enabling seamless interaction between these two programming languages.

## Features

Explore the diverse integration possibilities between C++ and Python with the following categories:

**1. Invoking C++ Wrapped Package in Python:**

* Python Calls C++ through Binding: Achieve seamless integration as Python code directly invokes C++ functions through binder.
* C++ Code Wrapped as Python Library: Enhance accessibility by transforming C++ code into a Python module using wrapping and exposure techniques.

**2. Invoking Python Class in C++:**

* C++ Invokes Python Function: Elevate your C++ application's capabilities by embedding a Python interpreter, enabling it to seamlessly call and utilize Python functions.

**3. Python-C++ Subprocess Interaction:**

* Python Spawns Subprocess for C++ Execution: Leverage the versatility of Python to initiate and manage C++ programs as separate subprocesses, allowing efficient inter-process communication.

## Directory Structure
```bash
CppPyIntegration/
│
├── CMakeLists.txt               # Root-level CMake configuration file
│
├── cpp/
│ ├── CMakeLists.txt             # C++ code CMake configuration file
│ ├── src/                       # C++ source code: binder_lib and wrapper_lib invocked in python
│ └── py_subprocess.cpp      
│
├── python/
│ └── cppCall.py                 # Python module invocked in C++ code
│
├── examples/
│ ├── python_import_cpp_binder.py       # Example: Python calls C++ through binding
│ ├── python_import_cpp_wrapper.py      # Example: C++ code wrapped as Python library
│ ├── python_spawn_subprocess.py        # Example: Python spawns subprocess for C++ execution
│ └── cpp_call_python_function.cpp      # Example: C++ invokes Python function
│
└── README.md                           # Project documentation

```
## Installation and Building

To build and run the examples, follow these steps:

1. **Building C++ Code**:
   - Navigate to the `cpp/` directory.
   - Follow the instructions in `CMakeLists.txt` to build the C++ code.

2. **Running Examples**:
   - Navigate to the `examples/` directory.
   - Run the desired example script using Python or execute the compiled C++ program.

## Usage

Each integration method has its own example script within the `examples/` directory. Follow these steps to try them out:

1. **Python Calls C++ through Binding**:
   - Navigate to the `examples/` directory.
   - Run `python_import_cpp_binder.py` to see Python calling C++ through binding.

2. **C++ Code Wrapped as Python Library**:
   - Build the C++ library according to the instructions in the `cpp/` directory.
   - Import the `your_python_module` module from the `python/` directory in your Python code.

3. **Python Spawns Subprocess for C++ Execution**:
   - Run `python_spawn_subprocess.py` in the `examples/` directory to see Python creating a subprocess for C++ execution.

4. **C++ Invokes Python Function**:
   - Build the C++ program using the instructions in the `examples/` directory.
   - Run the compiled program to see C++ invoking a Python function.

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to explore and adapt the integration methods to your specific needs!

For detailed instructions on each integration method, refer to the README files in their respective directories.

