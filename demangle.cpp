#include "demangle.hpp"

#include <cxxabi.h>
#include <memory>
#include <string>

namespace test
{
    std::string Demangle(const char* name)
    {
        char* buf = abi::__cxa_demangle(name, nullptr, nullptr, nullptr);
        std::string res = buf != nullptr ? buf : name;
        std::free(buf);
        return res;
    }
}
