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
    PyObject *pFunc1;
    PyObject *pFunc2;
    PyObject *pFunc3;
    PyObject *pArgs1;
    PyObject *pArgs2;
    PyObject *pArgs3;
    PyObject *pValue1;
    PyObject *pValue2;
    PyObject *pValue3;

    // Initialize the Python Interpreter
    Py_Initialize();

    // Load the module object
    pModule = PyImport_ImportModule("Python1");

    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);

    // pFunc1 is also a borrowed reference
    pFunc1 = PyDict_GetItemString(pDict, "do_int");
    pFunc2 = PyDict_GetItemString(pDict, "do_float");
    pFunc3 = PyDict_GetItemString(pDict, "do_str");

    // Build the arguments
    pArgs1 = PyTuple_New(3);
    pArgs2 = PyTuple_New(3);
    pArgs3 = PyTuple_New(3);
    PyTuple_SetItem(pArgs1, 0, PyLong_FromLong(2L));
    PyTuple_SetItem(pArgs1, 1, PyLong_FromLong(3L));
    PyTuple_SetItem(pArgs1, 2, PyLong_FromLong(4L));
    PyTuple_SetItem(pArgs2, 0, PyFloat_FromDouble(3.14));
    PyTuple_SetItem(pArgs2, 1, PyFloat_FromDouble(9.8));
    PyTuple_SetItem(pArgs2, 2, PyFloat_FromDouble(2.71828));
    PyTuple_SetItem(pArgs3, 0, PyUnicode_FromString("Joy"));
    PyTuple_SetItem(pArgs3, 1, PyUnicode_FromString("Bear"));
    PyTuple_SetItem(pArgs3, 2, PyUnicode_FromString("English"));

    // Call function
    pValue1 = PyObject_CallObject(pFunc1, pArgs1);
    printf("Return of call : %d\n", PyLong_AsLong(pValue1));

    // Call function
    pValue2 = PyObject_CallObject(pFunc2, pArgs2);
    printf("Return of call : %f\n", PyFloat_AsDouble(pValue2));

    // Call function
    pValue3 = PyObject_CallObject(pFunc3, pArgs3);
    printf("Return of call : %s\n", PyUnicode_AsUTF8(pValue3));

    // Clean up
    // pDict and pFunc are borrowed references so we don't need to Py_DECREF() them
    Py_DECREF(pModule);
    Py_DECREF(pArgs1);
    Py_DECREF(pArgs2);
    Py_DECREF(pArgs3);
    Py_DECREF(pValue1);
    Py_DECREF(pValue2);
    Py_DECREF(pValue3);

    // Finish the Python Interpreter
    Py_FinalizeEx();

    return EXIT_SUCCESS;
}