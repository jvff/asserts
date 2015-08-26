#ifndef COMMON_ASSERTIONS_HPP
#define COMMON_ASSERTIONS_HPP

#include "AssertionMethodMacros.hpp"

template <typename T>
class CommonAssertions {
public:
    CommonAssertions(const T&) {
    }

    ASSERTION(isMethod, false)
};

#endif
