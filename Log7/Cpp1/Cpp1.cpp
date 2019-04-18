// Since Python may define some pre-processor definitions
// which affect the standard headers on some systems,
// you must include Python.h before any standard headers are included.
// "Python.h" includes a few standard header files:
// <stdio.h>, <string.h>, <errno.h>, and <stdlib.h>
#include "Python.h"

#include <iostream>
#include <tchar.h>

using namespace std;

int main(int argc, char *argv[])
{
    PyObject *pModule;
    PyObject *pDict;
    PyObject *pClass;
    PyObject *pInstance;
    PyObject *pValue1;
    PyObject *pValue2;
    PyObject *pValue3;

    // Initialize the Python Interpreter
    Py_Initialize();

    // Load the module object
    pModule = PyImport_ImportModule("Python1");

    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);

    // Get "Adder" class object
    pClass = PyDict_GetItemString(pDict, "Adder");

    // Create an instance of the class
    pInstance = PyObject_CallObject(pClass, NULL);

    // Call a method of the class with three parameters
    // i : Convert a plain C int to a Python integer object
    pValue1 = PyObject_CallMethod(pInstance, "do_int", "(iii)", 2, 3, 4);
    printf("Return of call : %d\n", PyLong_AsLong(pValue1));

    // d : Convert a C double to a Python floating point number
    // f : Convert a C float to a Python floating point number
    pValue2 = PyObject_CallMethod(pInstance, "do_float", "(ddd)", 3.14, 9.8, 2.71828);
    printf("Return of call : %f\n", PyFloat_AsDouble(pValue2));

    // s : Convert a null-terminated C string to a Python str object using 'utf-8' encoding
    pValue3 = PyObject_CallMethod(pInstance, "do_str", "(sss)", "Joy", "Bear", "English");
    printf("Return of call : %s\n", PyUnicode_AsUTF8(pValue3));

    // Clean up
    // pDict is a borrowed reference so we don't need to Py_DECREF() it
    Py_DECREF(pModule);
    Py_DECREF(pClass);
    Py_DECREF(pInstance);
    Py_DECREF(pValue1);
    Py_DECREF(pValue2);
    Py_DECREF(pValue3);

    // Finish the Python Interpreter
    Py_FinalizeEx();

    return EXIT_SUCCESS;
}