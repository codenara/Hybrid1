#include "stdafx.h"
#include "Class1.h"

using namespace std;


Class1::Class1()
{
    cout << "in C++ native unmanaged Class1::Class1() Ctor." << endl;
}


Class1::~Class1()
{
    cout << "in C++ native unmanaged Class1::~Class1() ~Dtor." << endl;
}


void Class1::Say()
{
    cout << "in C++ native unmanaged Class1::Say() function." << endl;
}
