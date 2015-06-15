#ifndef ABSTRACT_TYPE_ASSERTION_TEST_HPP
#define ABSTRACT_TYPE_ASSERTION_TEST_HPP

#include "TypeOf.hpp"

#include "AbstractSimpleAssertionTest.hpp"
#include "TypeAssertionMacros.hpp"

template <typename T, bool shouldTSucceed>
class AbstractTypeAssertionTest :
        public AbstractSimpleAssertionTest<shouldTSucceed> {
private:
    typedef AbstractSimpleAssertionTest<shouldTSucceed> super;

public:
    template <typename... ParameterTypes>
    void checkResult(const std::string& failureMessage,
            ParameterTypes... messageParameters) {
        super::checkResult(failureMessage, TypeOf<T>(), messageParameters...);
    }
};

#endif
