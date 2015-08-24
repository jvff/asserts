#ifndef ABSTRACT_SIMPLE_ASSERTION_TEST_HPP
#define ABSTRACT_SIMPLE_ASSERTION_TEST_HPP

#include "AbstractAssertionTest.hpp"

template <bool shouldSucceed>
class AbstractSimpleAssertionTest : public AbstractAssertionTest {
public:
    template <typename... ParameterTypes>
    void checkResult(const std::string& failureMessage,
            const ParameterTypes&... messageParameters);
};

template <>
class AbstractSimpleAssertionTest<true> : public AbstractAssertionTest {
public:
    template <typename... ParameterTypes>
    void checkResult(const std::string&, const ParameterTypes&...) {
        this->shouldSucceed();
    }
};

template <>
class AbstractSimpleAssertionTest<false> : public AbstractAssertionTest {
public:
    template <typename... ParameterTypes>
    void checkResult(const std::string& failureMessage,
            const ParameterTypes&... messageParameters) {
        this->shouldFail(failureMessage, messageParameters...);
    }
};

#endif
