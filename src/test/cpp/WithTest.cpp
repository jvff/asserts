#include <type_traits>

#include "gtest/gtest.h"

#include "With.hpp"

#include "DummyTypes.hpp"

TEST(WithTest, noTemplateParams) {
    EXPECT_TRUE((std::is_class<With<> >::value));
}

TEST(WithTest, oneTemplateParam) {
    EXPECT_TRUE((std::is_class<With<DummyType> >::value));
}

TEST(WithTest, twoTemplateParams) {
    EXPECT_TRUE((std::is_class<With<DummyType, DummyType> >::value));
}

TEST(WithTest, threeTemplateParams) {
    EXPECT_TRUE((std::is_class<With<DummyType, DummyType, DummyType> >::value));
}
