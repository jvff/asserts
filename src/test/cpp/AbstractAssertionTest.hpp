#ifndef ABSTRACT_ASSERTION_TEST_HPP
#define ABSTRACT_ASSERTION_TEST_HPP

#include <boost/format.hpp>

#include "gtest/gtest.h"

#include "FakeTestReporter.hpp"

#include "asserts.hpp"

class AbstractAssertionTest : public testing::Test {
public:
    virtual void SetUp() {
        FakeTestReporter::reset();
    }

    virtual void TearDown() {
        FakeTestReporter::reset();
    }

    void shouldSucceed() {
        EXPECT_TRUE(FakeTestReporter::succeeded);
        EXPECT_FALSE(FakeTestReporter::failed);
    }

    template <typename... ParameterTypes>
    void shouldFail(const std::string& message, ParameterTypes... parameters) {
        shouldFail(boost::format(message), parameters...);
    }

    template <typename ParameterType, typename... ParameterTypes>
    void shouldFail(boost::format message, ParameterType parameter,
            ParameterTypes... parameters) {
        shouldFail(message % parameter, parameters...);
    }

    void shouldFail(boost::format& message) {
        shouldFail(message.str());
    }

    void shouldFail(const std::string& message) {
        EXPECT_FALSE(FakeTestReporter::succeeded);
        EXPECT_TRUE(FakeTestReporter::failed);
        EXPECT_EQ(message, *FakeTestReporter::failureMessage);
    }
};

#endif
