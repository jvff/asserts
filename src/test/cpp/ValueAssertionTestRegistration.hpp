#ifndef VALUE_ASSERTION_TEST_REGISTRATION_HPP
#define VALUE_ASSERTION_TEST_REGISTRATION_HPP

#include <regex>
#include <string>

#include "gtest/gtest.h"

#include "ExpressionRegEx.hpp"
#include "ValueAssertionTestFactory.hpp"

namespace testing {
namespace internal {

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed,
        typename... Tail>
class ValueAssertionTestRegistration {
private:
    static bool Register(const std::string&, const std::string&,
            std::sregex_iterator&, Tail&... parameters);
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
            const std::string& testName, std::sregex_iterator& parameterNames,
            ParameterType& parameter, Tail&... parameters) {
        static std::sregex_iterator endOfParameterNames;

        GTEST_CHECK_(parameterNames != endOfParameterNames)
            << "Parameter list parse error";

        auto parameterName = (*parameterNames).str();

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
            ParameterTypes&... parameters) {
        std::sregex_iterator parameterNamesIterator = { parameterNames.begin(),
                parameterNames.end(), ExpressionRegEx::getRegEx() };

        return ValueAssertionTestRegistration<FixtureClassTemplate,
                TestClassTemplate, shouldSucceed, ParameterTypes...>
                    ::Register(testCaseName, testName, parameterNamesIterator,
                            parameters...);
    }

    static bool Register(const std::string&, const std::string&,
            std::sregex_iterator&) {
        return true;
    }
};

}
}

#endif
