#ifndef CUSTOM_PARAMETERIZED_TEST_REGISTRATOR_HPP
#define CUSTOM_PARAMETERIZED_TEST_REGISTRATOR_HPP

#include <string>
#include <tuple>
#include <type_traits>

#include "gtest/gtest.h"

#include "ExpressionIterator.hpp"
#include "CustomParameterizedTestFactory.hpp"

namespace testing {
namespace internal {

template <template <typename> class FixtureClassTemplate,
        template <typename> class TestClassTemplate,
        typename... ParameterTypes>
class CustomParameterizedTestRegistrator {
private:
    using TupleType = std::tuple<const ParameterTypes&...>;
    using ThisType = CustomParameterizedTestRegistrator;

    static constexpr auto numParameters = std::tuple_size<TupleType>::value;

    template <bool condition>
    using EnableFor = typename std::enable_if<condition>::type;

    template <int index>
    using EnableForValid = EnableFor<index < numParameters>;

    template <int index>
    using EnableForInvalid = EnableFor<index >= numParameters>;

private:
    const std::string& testCaseName;
    const std::string& testName;
    ExpressionIterator parameterNames;
    TupleType parameters;

public:
    CustomParameterizedTestRegistrator(const std::string& testCase,
            const std::string& test, const std::string& parameterNamesString,
            const TupleType& parameterTuple) : testCaseName(testCase),
            testName(test), parameterNames(parameterNamesString),
            parameters(parameterTuple) {
    }

    void registerTest() {
        registerTestWithParameterAt<0>();
    }

private:
    template <int index>
    EnableForValid<index> registerTestWithParameterAt() {
        const auto& parameter = std::get<index>(parameters);

        registerTestWithParameter(parameter);

        registerTestWithParameterAt<index + 1>();
    }

    template <int index>
    EnableForInvalid<index> registerTestWithParameterAt() {
    }

    template <typename ParameterType>
    void registerTestWithParameter(const ParameterType& parameter) {
        GTEST_CHECK_(parameterNames.hasMore()) << "Parameter list parse error";

        const auto parameterName = *parameterNames;

        registerTestWithParameterNamed(parameterName, parameter);

        ++parameterNames;
    }

    template <typename ParameterType>
    void registerTestWithParameterNamed(const std::string& parameterName,
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
