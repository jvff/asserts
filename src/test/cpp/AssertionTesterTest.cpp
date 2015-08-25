#include <type_traits>

#include "gtest/gtest.h"

#include "AssertionTester.hpp"

TEST(AssertionTesterTest, classExists) {
    EXPECT_TRUE((std::is_class<AssertionTester>::value));
}
