#ifndef OPPOSITE_ASSERTION_TEST_TO_HPP
#define OPPOSITE_ASSERTION_TEST_TO_HPP

#include "VoidAssertionTest.hpp"

template <template <typename, bool> class FixtureClassTemplate,
         template <typename, bool> class TestClassTemplate>
struct OppositeAssertionTestTo {
    template <typename parameterType>
    using TestClass_succeeds = VoidAssertionTest<parameterType>;

    template <typename parameterType>
    using TestClass_fails = VoidAssertionTest<parameterType>;

    static const char TestCaseName[1];
};

template <template <typename, bool> class FixtureClassTemplate,
         template <typename, bool> class TestClassTemplate>
const char OppositeAssertionTestTo<FixtureClassTemplate, TestClassTemplate>
        ::TestCaseName[1] = "";

#endif
