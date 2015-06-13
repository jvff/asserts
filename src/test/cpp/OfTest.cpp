#include <type_traits>

#include "gtest/gtest.h"

#include "Of.hpp"

#include "DummyTypes.hpp"

TEST(OfTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<Of<DummyType> >::value));
}
