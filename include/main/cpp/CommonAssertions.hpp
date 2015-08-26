#ifndef COMMON_ASSERTIONS_HPP
#define COMMON_ASSERTIONS_HPP

#include "AssertionMethodMacros.hpp"

template <typename T>
class CommonAssertions {
protected:
    const T& subject;

public:
    CommonAssertions(const T& testSubject) : subject(testSubject) {
    }

    ASSERTION(isMethod, false)
};

#endif
