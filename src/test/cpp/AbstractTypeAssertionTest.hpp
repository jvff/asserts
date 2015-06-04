#ifndef ABSTRACT_TYPE_ASSERTION_TEST_HPP
#define ABSTRACT_TYPE_ASSERTION_TEST_HPP

#include "AbstractAssertionTest.hpp"
#include "TypeAssertionMacros.hpp"

template <typename T, bool shouldTSucceed>
class AbstractTypeAssertionTest : public AbstractAssertionTest {
public:
    void checkResult(const std::string& failureMessage);
};

template <typename T>
class AbstractTypeAssertionTest<T, true> : public AbstractAssertionTest {
public:
    void checkResult(const std::string&);
};

template <typename T>
class AbstractTypeAssertionTest<T, false> : public AbstractAssertionTest {
public:
    void checkResult(const std::string& failureMessage);
};

template <typename T>
void AbstractTypeAssertionTest<T, true>::checkResult(const std::string&) {
    this->shouldSucceed();
}

template <typename T>
void AbstractTypeAssertionTest<T, false>::checkResult(
        const std::string& failureMessage) {
    this->shouldFail(failureMessage);
}

#endif
