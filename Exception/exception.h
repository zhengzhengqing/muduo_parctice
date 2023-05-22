#pragma once
#include <stdio.h>
#include <iostream>
#include <cxxabi.h>
#include <execinfo.h>
#include <stdlib.h>

using namespace std;

class Exception : public std::exception
{
    public:
        explicit Exception(string what, bool demangle = false);
        ~Exception() noexcept override = default;

        const char* what() const noexcept override
        {
            return message_.c_str();
        }

        const char* stackTrace() const noexcept
        {
            return stack_.c_str();
        }

        string fillStackTrace(bool demangle);

    private:
        string message_;
        string stack_;
        bool demangle_;
};

