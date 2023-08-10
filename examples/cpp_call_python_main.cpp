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
    // Py_SetPath(Py_DecodeLocale(ROOT_PATH.c_str(), nullptr));
    PyObject* pModule  = PyImport_ImportModule("cppCall");

    if (pModule == nullptr) {
        PyErr_Print();
        std::cout << "ERROR: Failed to load 'cppCall'" << std::endl;
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
