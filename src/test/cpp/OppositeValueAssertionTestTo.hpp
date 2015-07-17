#ifndef OPPOSITE_VALUE_ASSERTION_TEST_TO_HPP
#define OPPOSITE_VALUE_ASSERTION_TEST_TO_HPP

#include "VoidValueAssertionTest.hpp"

template <template <typename, bool> class FixtureClassTemplate,
         template <typename, bool> class TestClassTemplate>
struct OppositeValueAssertionTestTo {
    template <typename parameterType>
    using TestClass_succeeds = VoidValueAssertionTest<parameterType>;

    template <typename parameterType>
    using TestClass_fails = VoidValueAssertionTest<parameterType>;

    static const char TestCaseName[1];
};

template <template <typename, bool> class FixtureClassTemplate,
         template <typename, bool> class TestClassTemplate>
const char OppositeValueAssertionTestTo<FixtureClassTemplate, TestClassTemplate>
        ::TestCaseName[1] = "";

#endif
