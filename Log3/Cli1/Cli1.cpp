#include "stdafx.h"
#include "Class1.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine("in C++/CLI managed main() function");

    Class1 c1;
    c1.Say();

    return 0;
}
