#ifndef TYPE_OF_TEST_HPP
#define TYPE_OF_TEST_HPP

#include <type_traits>

#include "gtest/gtest.h"

#include "TypeOf.hpp"

#include "DummyTypes.hpp"

TEST(TypeOfTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<TypeOf<DummyType> >::value));
}

#endif
