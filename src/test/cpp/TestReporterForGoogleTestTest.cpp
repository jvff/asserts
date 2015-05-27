#include <type_traits>

#include "gtest/gtest.h"

#include "TestReporter.hpp"

TEST(TestReporterForGoogleTestTest, testReporterTypeAliasWasDefined) {
    EXPECT_TRUE((std::is_same<GoogleTestReporter, TestReporter>::value));
}
