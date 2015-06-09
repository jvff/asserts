#ifndef ABSTRACT_SIMPLE_ASSERTION_TEST_HPP
#define ABSTRACT_SIMPLE_ASSERTION_TEST_HPP

#include "AbstractAssertionTest.hpp"

template <bool shouldSucceed>
class AbstractSimpleAssertionTest : public AbstractAssertionTest {
public:
    void checkResult(const std::string& failureMessage);
};

template <>
class AbstractSimpleAssertionTest<true> : public AbstractAssertionTest {
public:
    void checkResult(const std::string&) {
        this->shouldSucceed();
    }
};

template <>
class AbstractSimpleAssertionTest<false> : public AbstractAssertionTest {
public:
    void checkResult(const std::string& failureMessage) {
        this->shouldFail(failureMessage);
    }
};

#endif
