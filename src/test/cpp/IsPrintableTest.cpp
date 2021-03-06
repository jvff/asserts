#include <gtest/gtest.h>

#include "IsPrintable.hpp"

#include "PrintableClass.hpp"
#include "UnprintableClass.hpp"

TEST(IsPrintableTest, boolIsPrintable) {
    EXPECT_TRUE((IsPrintable<bool>::value));
}

TEST(IsPrintableTest, unprintableClassIsntPrintable) {
    EXPECT_FALSE((IsPrintable<UnprintableClass>::value));
}

TEST(IsPrintableTest, printableClassIsPrintable) {
    EXPECT_TRUE((IsPrintable<PrintableClass>::value));
}
