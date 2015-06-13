#ifndef TYPE_OF_TEST_HPP
#define TYPE_OF_TEST_HPP

#include <sstream>
#include <type_traits>

#include "gtest/gtest.h"

#include "TypeOf.hpp"

#include "DummyTypes.hpp"

TEST(TypeOfTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<TypeOf<DummyType> >::value));
}

TEST(TypeOfTest, outputStreamOperatorForInt) {
    std::stringstream stream;

    stream << TypeOf<int>();

    EXPECT_EQ("int", stream.str());
}

#endif
