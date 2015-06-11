#ifndef VALUE_ASSERTION_TEST_FACTORY_HPP
#define VALUE_ASSERTION_TEST_FACTORY_HPP

#include "gtest/gtest.h"

namespace testing {
namespace internal {

template <class TestClass, typename ParamType>
class ValueAssertionTestFactory : public TestFactoryBase {
private:
    ParamType& parameter;

public:
    ValueAssertionTestFactory(ParamType& testParameter) :
            parameter(testParameter) {
    }

    Test* CreateTest() override {
        return new TestClass(parameter);
    }
};

}
}

#endif
