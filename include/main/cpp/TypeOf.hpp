#ifndef TYPE_OF_HPP
#define TYPE_OF_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>

#include <cxxabi.h>

template <typename T>
class TypeOf {
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const TypeOf<T>&) {
    const char* name = typeid(T).name();
    const char* demangledName;
    int demangleSucceeded = 0;

    demangledName = abi::__cxa_demangle(name, NULL, NULL, &demangleSucceeded);

    if (demangleSucceeded == 0)
        out << demangledName;
    else
        out << name;

    std::free((void*)demangledName);

    return out;
}

#endif
