#ifndef IS_PRINTABLE_HPP
#define IS_PRINTABLE_HPP

#include <iostream>

template <typename T>
struct IsPrintable {
    typedef char (&yes)[1];
    typedef char (&no)[2];

    template <typename U>
    static yes test(U* u, std::ostream* stream, decltype(&(*stream << *u)));

    template <typename U>
    static no test(...);

    static const bool value = sizeof(test<T>(0, 0, 0)) == sizeof(yes);
};

#endif
