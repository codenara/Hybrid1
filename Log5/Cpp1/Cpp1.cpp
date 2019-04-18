// Creating a C++ extension for Python
// https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio

// Since Python may define some pre-processor definitions
// which affect the standard headers on some systems,
// you must include Python.h before any standard headers are included.
// "Python.h" includes a few standard header files:
// <stdio.h>, <string.h>, <errno.h>, and <stdlib.h>
#include "Python.h"

// Module function
// self unused in modules
// args from Python call
// Modify the method to accept and return Python types (PyOjbect*)
PyObject *DoLong(PyObject *self, PyObject *args)
{
    long myLong = PyLong_AsLong(args);
    myLong = myLong * 2;
    return PyLong_FromLong(myLong);
}

PyObject *DoDouble(PyObject *self, PyObject *args)
{
    double myDouble = PyFloat_AsDouble(args);
    myDouble = myDouble * 2.0;
    return PyFloat_FromDouble(myDouble);
}

static PyObject *DoString(PyObject *self, PyObject *args)
{
    char *myString;
    char result[1024];
    PyArg_ParseTuple(args, "s", &myString); // convert Python -> C
    strcpy(result, "Hello, ");              // build up C string
    strcat(result, myString);               // add passed Python string
    return Py_BuildValue("s", result);      // convert C -> Python
}

// Registration table
// Add a structure that defines how the C++ functions are presented to Python
static PyMethodDef Cpp1Methods[] = {
    // The first property is the name exposed to Python.
    // The second property is the C++ function name that contains the implementation.
    // name, &function, format, doc
    {"DoLong", (PyCFunction)DoLong, METH_O, nullptr},
    {"DoDouble", (PyCFunction)DoDouble, METH_O, nullptr},
    {"DoString", (PyCFunction)DoString, METH_VARARGS, "func doc"},

    // Terminate the array with an object containing nulls.
    {nullptr, nullptr, 0, nullptr} // end of table marker
};

// Module definition structure
// Add a structure that defines the module
// as you want to refer to it in your Python code,
// specifically when using the from...import statement.
// Make this match the value in the project properties
// under Configuration Properties > General > Target Name
static PyModuleDef Cpp1Module = {
    PyModuleDef_HEAD_INIT,
    "Cpp1",          // Module name to use with Python import statements
    "C++ Extension", // Module documentation, may be NULL
    0,               // size of per-interpreter module state, -1=in global vars
    Cpp1Methods      // Structure that defines the methods of the module
};

// Module initializer
// Add a method that Python calls when it loads the module,
// which must be named PyInit_<module-name>,
// where <module_name> exactly matches
// the C++ Project's Properties > General > Target Name property,
// that is, it matches the filename of the .pyd built by the project.
PyMODINIT_FUNC PyInit_Cpp1() // called on first import
{                            // name matters if loaded dynamically
    return PyModule_Create(&Cpp1Module);
}
