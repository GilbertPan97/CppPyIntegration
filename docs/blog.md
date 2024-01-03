## C++与Python的混合编程

随着软件开发领域的不断演进，特别是在深度学习领域中日益发展，对于不同编程语言之间的整合需求也愈发增加。在这篇博客中，我们将探讨如何实现C++与Python之间的混合编程，按照程序的工作模式，我们分为三类，在C++中调用Python方法、在Python中调用C++的封装库，以及实现Python程序与C++程序之间的通信。

### 在C++中调用Python方法

在某些情况下，你可能需要利用Python的灵活性和库来扩展已存在的C++应用程序。一种方法是在C++代码中嵌入Python解释器，并在C++中调用Python类。

在

```
#include <Python.h>
#include <iostream>
#include <vector>
#include <filesystem>   // For C++17 or later

#if WIN32
std::string ROOT_PATH = std::filesystem::current_path().string() + "/../../";
#else
std::string ROOT_PATH = std::filesystem::current_path().string() + "/../";
#endif

int main() 
{
    // Step 1: Initialize Python interpreter
    Py_Initialize();
    if (!Py_IsInitialized()) {
        std::cout << "ERROR: Python initialization failed" << std::endl;
        return -1;
    }

    // Step 2: Set Python module search path
    std::string relativePath = "/venv/Scripts";
    std::string fullPath = ROOT_PATH + relativePath;
    const wchar_t* pythonPath = Py_DecodeLocale(fullPath.c_str(), nullptr);
    Py_SetPath(pythonPath);
    char buffer[256];
    wcstombs(buffer, pythonPath, sizeof(buffer));
    std::cout << "INFO: Python interpreter search path is: " << buffer << std::endl;

    // Step 3: Call Python script and pass data
    PyObject* pModule  = PyImport_ImportModule("py_module");

    if (pModule == nullptr) {
        PyErr_Print();
        std::cout << "ERROR: Failed to load 'py_module'" << std::endl;
        return -1;
    }
    
    // Step 3.1: Get Python function object
    PyObject* pFunc = PyObject_GetAttrString(pModule, "process_and_send_data");
    if (pFunc && PyCallable_Check(pFunc)) {
        // Step 3.2: Prepare data
        int numBoxes = 5;
        std::vector<float> angles = {45.5f, 30.0f, 60.2f, 90.8f, 120.1f};

        // Step 3.3: Convert data to Python objects
        PyObject* pNumBoxes = PyLong_FromLong(numBoxes);
        PyObject* pAngles = PyList_New(angles.size());
        for (size_t i = 0; i < angles.size(); ++i) {
            PyList_SetItem(pAngles, i, PyFloat_FromDouble(static_cast<double>(angles[i])));
        }

        // Step 3.4: Build function argument tuple
        PyObject* pArgs = PyTuple_Pack(2, pNumBoxes, pAngles);

        // Step 3.5: Call Python function
        PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);

        if (pValue != nullptr) {
            // Step 3.6: Handle Python function return value
            const char* response = PyUnicode_AsUTF8(pValue);
            std::cout << "Response from Python: " << response << std::endl;
            Py_DECREF(pValue);
        }
        else {
            PyErr_Print();
        }
    }
    else {
        if (PyErr_Occurred()) PyErr_Print();
        std::cout << "Cannot find function 'process_and_send_data'" << std::endl;
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);

    // Step 4: Clean up resources and close Python interpreter
    Py_Finalize();

    return 0;
}
```



### 在Python中调用C++封装库

有时，你可能需要在Python中利用C++的性能和功能来执行特定任务。

### Python程序与C++程序通信

考虑的是如何在Python程序和C++程序之间进行通信。一种通用方法是使用进程间通信（Inter-Process Communication，IPC），例如通过套接字、共享内存或消息队列来实现。