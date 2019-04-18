#pragma once
class Native
{
public:
    Native();
    ~Native();
    int DoInt(int number);
    double DoDouble(double number);
    CString DoString(CString text);
};
