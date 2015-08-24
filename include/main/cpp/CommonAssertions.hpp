#ifndef COMMON_ASSERTIONS_HPP
#define COMMON_ASSERTIONS_HPP

#include <string>

#include <boost/format.hpp>

#include "AssertionMethodMacros.hpp"
#include "Formatter.hpp"
#include "TestReporter.hpp"

class CommonAssertions {
public:
    ASSERTION(isMethod, false)

protected:
    static void test(bool result, const std::string& failureMessage) {
        if (result == true)
            TestReporter::succeed();
        else
            TestReporter::fail(failureMessage);
    }

    template <typename... ParameterTypes>
    static void test(bool result, const std::string& failureMessage,
            const ParameterTypes&... messageParameters) {
        if (result == true)
            TestReporter::succeed();
        else
            fail(boost::format(failureMessage), messageParameters...);
    }

    static void fail(boost::format failureMessage) {
        TestReporter::fail(failureMessage.str());
    }

    template <typename ParameterType, typename... ParameterTypes>
    static void fail(boost::format failureMessage,
            const ParameterType& messageParameter,
            const ParameterTypes&... messageParameters) {
        fail(failureMessage % format(messageParameter), messageParameters...);
    }
};

#endif
