#include <type_traits>

#include "gtest/gtest.h"

#include "CommonAssertions.hpp"

TEST(CommonAssertionsTest, classExists) {
    EXPECT_TRUE((std::is_class<CommonAssertions>::value));
}
