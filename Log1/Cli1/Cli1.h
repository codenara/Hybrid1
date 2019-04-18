#pragma once

#include <atlstr.h>	// for CString https://docs.microsoft.com/en-us/cpp/atl-mfc-shared/using-cstring
#include "Native.h"

using namespace System;

namespace Cli1 {
	public ref class Managed
	{
    public:
        __clrcall Managed()
        {
            Console::WriteLine(L"in Managed Ctor");
            m_Native = new Native();
            System::Diagnostics::Debug::Assert(m_Native != nullptr);
        }

        virtual __clrcall ~Managed()
        {
            ReleaseResource();
            Console::WriteLine(L"in Managed ~Dtor");
        }

        __clrcall !Managed()
        {
            ReleaseResource();
            Console::WriteLine(L"in Managed !Fzer");
        }

        int __clrcall DoInt(int x)
        {
            Console::WriteLine(L"in Managed DoInt");
            return m_Native->DoInt(x);
        }

        double __clrcall DoDouble(double x)
        {
            Console::WriteLine(L"in Managed DoDouble");
            return m_Native->DoDouble(x);
        }

        String^ __clrcall DoString(String^ x)
        {
            Console::WriteLine(L"in Managed DoString");

            // String^ to CString Conversion
            CString cstr = x; // or CString cstr(x);

            CString rslt = m_Native->DoString(cstr);

            // CString to String^ Conversion
            String ^mstr = gcnew String(rslt);

            return mstr;
        }

    private:
        void ReleaseResource()
        {
            if (m_Native != nullptr)
            {
                delete m_Native;
            }
        }

    private:
        Native *m_Native = nullptr;	// Native C++ member
    };
}
