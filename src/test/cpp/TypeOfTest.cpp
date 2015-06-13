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

#define TEST_TYPE_OF(TypeName, Type) \
TEST(TypeOfTest, outputStreamOperatorFor##TypeName) { \
    std::stringstream stream; \
\
    stream << TypeOf<Type>(); \
\
    EXPECT_EQ(#Type, stream.str()); \
}

TEST_TYPE_OF(Int, int)

#endif
