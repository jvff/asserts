#include "gtest/gtest.h"

#include "asserts.hpp"

#include "DummyTypes.hpp"

TEST(AssertThatTest, classExists) {
    EXPECT_TRUE((std::is_class<AssertThat<DummyType> >::value));
}
