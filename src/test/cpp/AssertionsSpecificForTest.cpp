#include <type_traits>

#include "gtest/gtest.h"

#include "AssertionsSpecificFor.hpp"

#include "DummyTypes.hpp"

TEST(AssertionsSpecificForTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<AssertionsSpecificFor<DummyType> >::value));
}
