#include "gtest/gtest.h"

#include "asserts.hpp"

#include "DummyTypes.hpp"

TEST(AssertThatTest, classExists) {
    EXPECT_TRUE((std::is_class<AssertThat<DummyType> >::value));
}

TEST(AssertThatTest, hasConstructorWithParameter) {
    typedef AssertThat<DummyType> type;
    typedef const DummyType& parameter;

    EXPECT_TRUE((std::is_constructible<type, parameter>::value));
}
