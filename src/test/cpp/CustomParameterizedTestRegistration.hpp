#ifndef CUSTOM_PARAMETERIZED_TEST_REGISTRATION_HPP
#define CUSTOM_PARAMETERIZED_TEST_REGISTRATION_HPP

#include <string>
#include <tuple>
#include <type_traits>

#include "gtest/gtest.h"

#include "ExpressionIterator.hpp"
#include "CustomParameterizedTestFactory.hpp"
#include "CustomParameterizedTestRegistrator.hpp"

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
        using Registrator = CustomParameterizedTestRegistrator<
                FixtureClassTemplate, TestClassTemplate, ParameterTypes...>;

        Registrator(testCaseName, testName, parameterNames, parameters)
            .registerTest();

        return true;
    }
};

}
}

#endif
