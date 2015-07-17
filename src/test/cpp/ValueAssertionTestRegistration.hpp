#ifndef VALUE_ASSERTION_TEST_REGISTRATION_HPP
#define VALUE_ASSERTION_TEST_REGISTRATION_HPP

#include <string>

#include "gtest/gtest.h"

#include "ExpressionIterator.hpp"
#include "ValueAssertionTestFactory.hpp"
#include "VoidValueAssertionTest.hpp"

namespace testing {
namespace internal {

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed,
        typename... Tail>
class ValueAssertionTestRegistration {
private:
    static bool Register(const std::string&, const std::string&,
            ExpressionIterator&, const Tail&... parameters);
};

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed,
        typename ParameterType, typename... Tail>
class ValueAssertionTestRegistration<FixtureClassTemplate, TestClassTemplate,
        shouldSucceed, ParameterType, Tail...> {
private:
    typedef TestClassTemplate<ParameterType> TestClass;
    typedef FixtureClassTemplate<ParameterType, shouldSucceed> FixtureClass;
    typedef ValueAssertionTestFactory<TestClass, ParameterType> TestFactory;

public:
    static bool Register(const std::string& testCaseName,
            const std::string& testName, ExpressionIterator& parameterNames,
            const ParameterType& parameter, const Tail&... parameters) {
        GTEST_CHECK_(parameterNames.hasMore()) << "Parameter list parse error";

        std::string parameterName = *parameterNames;
        std::string currentTestCaseName = testCaseName + "." + parameterName;

        MakeAndRegisterTestInfo(currentTestCaseName.c_str(), testName.c_str(),
                NULL, NULL, GetTypeId<FixtureClass>(), TestClass::SetUpTestCase,
                TestClass::TearDownTestCase, new TestFactory(parameter));

        ++parameterNames;

        return ValueAssertionTestRegistration<FixtureClassTemplate,
                TestClassTemplate, shouldSucceed, Tail...>
                    ::Register(testCaseName, testName, parameterNames,
                            parameters...);
    }
};

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed>
class ValueAssertionTestRegistration<FixtureClassTemplate, TestClassTemplate,
        shouldSucceed> {
public:
    template <typename... ParameterTypes>
    static bool Register(const std::string& testCaseName,
            const std::string& testName, const std::string& parameterNames,
            const ParameterTypes&... parameters) {
        ExpressionIterator parameterNamesIterator(parameterNames);

        return ValueAssertionTestRegistration<FixtureClassTemplate,
                TestClassTemplate, shouldSucceed, ParameterTypes...>
                    ::Register(testCaseName, testName, parameterNamesIterator,
                            parameters...);
    }

    static bool Register(const std::string&, const std::string&,
            ExpressionIterator&) {
        return true;
    }
};

template <template <typename, bool> class FixtureClassTemplate,
        bool shouldSucceed>
class ValueAssertionTestRegistration<FixtureClassTemplate,
        VoidValueAssertionTest, shouldSucceed> {
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
