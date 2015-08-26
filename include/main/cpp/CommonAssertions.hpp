#ifndef COMMON_ASSERTIONS_HPP
#define COMMON_ASSERTIONS_HPP

#include "AssertionMethodMacros.hpp"

template <typename T>
class CommonAssertions {
protected:
    const T& subject;

    AssertionTester::InvalidParameter noMessageParameters;

public:
    CommonAssertions(const T& testSubject) : subject(testSubject) {
    }

    ASSERTION(isConstMethod, false, noMessageParameters)
};

#endif
