#include <type_traits>

#include "gtest/gtest.h"

#include "FakeTestReporter.hpp"

#include "TestReporter.hpp"

TEST(TestReporterTest, testReporterTypeAliasWasDefined) {
    EXPECT_TRUE((std::is_same<FakeTestReporter, TestReporter>::value));
}
