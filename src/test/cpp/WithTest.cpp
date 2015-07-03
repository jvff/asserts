#include <type_traits>

#include "gtest/gtest.h"

#include "With.hpp"

#include "DummyTypes.hpp"

TEST(WithTest, noTemplateParams) {
    EXPECT_TRUE((std::is_class<With<> >::value));
}
