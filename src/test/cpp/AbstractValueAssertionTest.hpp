#ifndef ABSTRACT_VALUE_ASSERTION_TEST_HPP
#define ABSTRACT_VALUE_ASSERTION_TEST_HPP

#include "gtest/gtest.h"

#include "AbstractSimpleAssertionTest.hpp"
#include "ValueAssertionMacros.hpp"

template <typename T, bool shouldSucceed>
class AbstractValueAssertionTest :
        public AbstractSimpleAssertionTest<shouldSucceed> {
public:
    typedef T ParamType;
};

#endif
