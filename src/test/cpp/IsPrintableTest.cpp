#include <gtest/gtest.h>

#include "IsPrintable.hpp"

TEST(IsPrintableTest, boolIsPrintable) {
    EXPECT_TRUE((IsPrintable<bool>::value));
}
