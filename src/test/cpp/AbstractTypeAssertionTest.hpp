#ifndef ABSTRACT_TYPE_ASSERTION_TEST_HPP
#define ABSTRACT_TYPE_ASSERTION_TEST_HPP

#include "AbstractAssertionTest.hpp"

template <typename T>
class Should {
public:
    static const bool succeed;
};

template <typename T>
class AbstractTypeAssertionTest : public AbstractAssertionTest {
public:
    void checkResult(const std::string& failureMessage) {
        if (Should<T>::succeed)
            this->shouldSucceed();
        else
            this->shouldFail(failureMessage);
    }
};

#define SHOULD_SUCCEED(type) \
template <> \
const bool Should<type>::succeed = true

#define SHOULD_FAIL(type) \
template <> \
const bool Should<type>::succeed = false

#endif
