#ifndef ABSTRACT_ASSERTION_TEST_HPP
#define ABSTRACT_ASSERTION_TEST_HPP

#include "gtest/gtest.h"

#include "FakeTestReporter.hpp"

#include "asserts.hpp"

class AbstractAssertionTest : public testing::Test {
public:
    virtual void SetUp() {
        FakeTestReporter::reset();
    }

    void shouldSucceed() {
        EXPECT_TRUE(FakeTestReporter::succeeded);
        EXPECT_FALSE(FakeTestReporter::failed);
    }

    void shouldFail(const std::string& message) {
        EXPECT_FALSE(FakeTestReporter::succeeded);
        EXPECT_TRUE(FakeTestReporter::failed);
        EXPECT_EQ(message, FakeTestReporter::failureMessage.get());
    }
};

#endif
