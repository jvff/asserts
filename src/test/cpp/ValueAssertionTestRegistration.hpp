#ifndef VALUE_ASSERTION_TEST_REGISTRATION_HPP
#define VALUE_ASSERTION_TEST_REGISTRATION_HPP

#include <string>

#include "gtest/gtest.h"

#include "CustomParameterizedTestRegistration.hpp"
#include "VoidAssertionTest.hpp"

namespace testing {
namespace internal {

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed>
class ValueAssertionTestRegistration {
private:
    template <typename T>
    using FixtureClassTemplateWrapper = FixtureClassTemplate<T, shouldSucceed>;

public:
    template <typename... ParameterTypes>
    static bool Register(const std::string& testCaseName,
            const std::string& testName, const std::string& parameterNames,
            const ParameterTypes&... parameters) {
        return CustomParameterizedTestRegistration<FixtureClassTemplateWrapper,
                TestClassTemplate>
                    ::Register(testCaseName, testName, parameterNames,
                            parameters...);
    }
};

template <template <typename, bool> class FixtureClassTemplate,
        bool shouldSucceed>
class ValueAssertionTestRegistration<FixtureClassTemplate,
        VoidAssertionTest, shouldSucceed> {
public:
    template <typename... ParameterTypes>
    static bool Register(const std::string&, const std::string&,
            const std::string&, const ParameterTypes&...) {
        return false;
    }
};

}
}

#endif
