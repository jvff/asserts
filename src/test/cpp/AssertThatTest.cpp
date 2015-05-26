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

TEST(AssertThatTest, hasNoOtherConstructor) {
    typedef AssertThat<DummyType> type;
    typedef const DummyType& parameter;

    EXPECT_FALSE((std::is_default_constructible<type>::value));
    EXPECT_FALSE((std::is_copy_constructible<type>::value));
    EXPECT_FALSE((std::is_move_constructible<type>::value));
}

TEST(AssertThatTest, auxiliaryFunctionExists) {
    const DummyType parameter;
    const DummyType& parameterReference = parameter;

    typedef AssertThat<DummyType> type;
    typedef decltype(assertThat(parameterReference)) returnType;

    EXPECT_TRUE((std::is_same<type, returnType>::value));
}
