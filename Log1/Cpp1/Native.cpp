#include "stdafx.h"
#include "Native.h"

using namespace std;

Native::Native()
{
    cout << "in Native Ctor" << endl;
}


Native::~Native()
{
    cout << "in Native ~Dtor" << endl;
}


int Native::DoInt(int number)
{
    cout << "in Native DoInt" << endl;
    return (2 * number);
}


double Native::DoDouble(double number)
{
    cout << "in Native DoDouble" << endl;
    return (2.0 * number);
}


CString Native::DoString(CString text)
{
    cout << "in Native DoString" << endl;
    return (text + text);
}
