// Suppress error messages about obsolete & deprecated functions
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

// Since Python may define some pre-processor definitions
// which affect the standard headers on some systems,
// you must include Python.h before any standard headers are included.
// "Python.h" includes a few standard header files:
// <stdio.h>, <string.h>, <errno.h>, and <stdlib.h>
#include "Python.h"

#include <iostream>

int main(int argc, char *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    Py_SetProgramName(program); // optional but recommended
    Py_Initialize();

    PyRun_SimpleString("from time import time, ctime\n"
        "print('Today is', ctime(time()))\n");

    FILE* file = fopen("Python1.py", "r");
    PyRun_SimpleFile(file, "Python1.py");
    fclose(file);

    Py_FinalizeEx();
    PyMem_RawFree(program);

    return EXIT_SUCCESS;
}
