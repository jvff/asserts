#ifndef CUSTOM_PARAMETERIZED_TEST_REGISTRATION_HPP
#define CUSTOM_PARAMETERIZED_TEST_REGISTRATION_HPP

#include <string>
#include <tuple>
#include <type_traits>

#include "gtest/gtest.h"

#include "ExpressionIterator.hpp"
#include "CustomParameterizedTestFactory.hpp"

namespace testing {
namespace internal {

template <template <typename> class FixtureClassTemplate,
        template <typename> class TestClassTemplate>
class CustomParameterizedTestRegistration {
public:
    template <typename... ParameterTypes>
    static bool Register(const std::string& testCaseName,
            const std::string& testName, const std::string& parameterNames,
            const ParameterTypes&... parameters) {
        auto parameterTuple = std::tie(parameters...);

        return Register(testCaseName, testName, parameterNames, parameterTuple);
    }

    template <typename... ParameterTypes>
    static bool Register(const std::string& testCaseName,
            const std::string& testName, const std::string& parameterNames,
            const std::tuple<const ParameterTypes&...>& parameters) {
        using ParameterTuple = std::tuple<const ParameterTypes&...>;

        constexpr auto numParameters = std::tuple_size<ParameterTuple>::value;
        ExpressionIterator parameterNamesIterator(parameterNames);

        registerForParameterIndex<ParameterTuple, 0, numParameters>(
                testCaseName, testName, parameterNamesIterator, parameters);

        return true;
    }

private:
    template <typename ParameterTuple, int ParameterIndex, int NumParameters>
    static typename std::enable_if<ParameterIndex < NumParameters>::type
            registerForParameterIndex(const std::string& testCaseName,
                    const std::string& testName,
                    ExpressionIterator& parameterNames,
                    const ParameterTuple& parameters) {
        const auto& parameter = std::get<ParameterIndex>(parameters);

        registerForParameter(testCaseName, testName, parameterNames,
                parameter);

        registerForParameterIndex<ParameterTuple, ParameterIndex + 1,
                NumParameters>(testCaseName, testName, parameterNames,
                        parameters);
    }

    template <typename ParameterTuple, int ParameterIndex, int NumParameters>
    static typename std::enable_if<ParameterIndex == NumParameters>::type
            registerForParameterIndex(const std::string&, const std::string&,
                    ExpressionIterator&, const ParameterTuple&) {
    }

    template <typename ParameterType>
    static void registerForParameter(const std::string& testCaseName,
            const std::string& testName, ExpressionIterator& parameterNames,
            const ParameterType& parameter) {
        GTEST_CHECK_(parameterNames.hasMore()) << "Parameter list parse error";

        const auto parameterName = *parameterNames;

        registerForParameter(testCaseName, testName, parameterName, parameter);

        ++parameterNames;
    }

    template <typename ParameterType>
    static void registerForParameter(const std::string& testCaseName,
            const std::string& testName, const std::string& parameterName,
            const ParameterType& parameter) {
        using FixtureClass = FixtureClassTemplate<ParameterType>;
        using TestClass = TestClassTemplate<ParameterType>;
        using TestFactory = CustomParameterizedTestFactory<TestClass,
                ParameterType>;

        std::string currentTestCaseName = testCaseName + "." + parameterName;

        MakeAndRegisterTestInfo(currentTestCaseName.c_str(), testName.c_str(),
                NULL, NULL, GetTypeId<FixtureClass>(), TestClass::SetUpTestCase,
                TestClass::TearDownTestCase, new TestFactory(parameter));
    }
};

}
}

#endif
