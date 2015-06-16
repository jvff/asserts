#ifndef ABSTRACT_TYPE_ASSERTION_TEST_HPP
#define ABSTRACT_TYPE_ASSERTION_TEST_HPP

#include <tuple>

#include "TypeOf.hpp"

#include "AbstractSimpleAssertionTest.hpp"
#include "TypeAssertionMacros.hpp"

template <typename TypeParam, typename TypeToName, bool shouldSucceed>
class AbstractTypeAssertionTestParent :
        public AbstractSimpleAssertionTest<shouldSucceed> {
private:
    typedef AbstractSimpleAssertionTest<shouldSucceed> super;

public:
    template <typename... ParameterTypes>
    void checkResult(const std::string& failureMessage,
            ParameterTypes... messageParameters) {
        auto typeName = TypeOf<TypeToName>();

        super::checkResult(failureMessage, typeName, messageParameters...);
    }
};

template <typename T, bool shouldSucceed>
class AbstractTypeAssertionTest :
        public AbstractTypeAssertionTestParent<T, T, shouldSucceed> {
};

template <typename T, bool shouldSucceed, typename... ExtraTypes>
class AbstractTypeAssertionTest<std::tuple<T, ExtraTypes...>, shouldSucceed> :
        public AbstractTypeAssertionTestParent<std::tuple<T, ExtraTypes...>, T,
                shouldSucceed> {
};

#endif
