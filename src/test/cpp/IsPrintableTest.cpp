#include <gtest/gtest.h>

#include "IsPrintable.hpp"

#include "IsPrintableTest.hpp"

TEST(IsPrintableTest, boolIsPrintable) {
    EXPECT_TRUE((IsPrintable<bool>::value));
}

TEST(IsPrintableTest, unprintableClassIsntPrintable) {
    EXPECT_FALSE((IsPrintable<UnprintableClass>::value));
}
