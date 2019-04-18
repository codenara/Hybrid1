// Cpp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#pragma managed

void mfoo() {
    System::Console::WriteLine("in managed function.");
}

#pragma unmanaged

void ufoo() {
    cout << "in unmanaged function." << endl;
}

// "main()" function can be "managed" or "unmanaged"
//#pragma managed
#pragma unmanaged

int main()
{
    mfoo();
    ufoo();

    return 0;
}
