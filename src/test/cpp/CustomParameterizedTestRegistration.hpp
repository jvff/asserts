#ifndef CUSTOM_PARAMETERIZED_TEST_REGISTRATION_HPP
#define CUSTOM_PARAMETERIZED_TEST_REGISTRATION_HPP

#include <string>

#include "gtest/gtest.h"

#include "ExpressionIterator.hpp"
#include "CustomParameterizedTestFactory.hpp"

namespace testing {
namespace internal {

template <template <typename> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, typename... Tail>
class CustomParameterizedTestRegistration {
private:
    static bool Register(const std::string&, const std::string&,
            ExpressionIterator&, const Tail&... parameters);
};

template <template <typename> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, typename ParameterType,
        typename... Tail>
class CustomParameterizedTestRegistration<FixtureClassTemplate,
        TestClassTemplate, ParameterType, Tail...> {
private:
    typedef TestClassTemplate<ParameterType> TestClass;
    typedef FixtureClassTemplate<ParameterType> FixtureClass;
    typedef CustomParameterizedTestFactory<TestClass, ParameterType>
            TestFactory;

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

        return CustomParameterizedTestRegistration<FixtureClassTemplate,
                TestClassTemplate, Tail...>
                    ::Register(testCaseName, testName, parameterNames,
                            parameters...);
    }
};

template <template <typename> class FixtureClassTemplate,
        template <typename> class TestClassTemplate>
class CustomParameterizedTestRegistration<FixtureClassTemplate,
        TestClassTemplate> {
public:
    template <typename... ParameterTypes>
    static bool Register(const std::string& testCaseName,
            const std::string& testName, const std::string& parameterNames,
            const ParameterTypes&... parameters) {
        ExpressionIterator parameterNamesIterator(parameterNames);

        return CustomParameterizedTestRegistration<FixtureClassTemplate,
                TestClassTemplate, ParameterTypes...>
                    ::Register(testCaseName, testName, parameterNamesIterator,
                            parameters...);
    }

    static bool Register(const std::string&, const std::string&,
            ExpressionIterator&) {
        return true;
    }
};

}
}

#endif
