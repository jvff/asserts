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

TEST_TYPE_OF(Bool, bool)
TEST_TYPE_OF(Char, char)
TEST_TYPE_OF(ShortInt, short)
TEST_TYPE_OF(Int, int)
TEST_TYPE_OF(LongInt, long)
TEST_TYPE_OF(LongLongInt, long long)
TEST_TYPE_OF(UnsignedChar, unsigned char)
TEST_TYPE_OF(UnsignedShortInt, unsigned short)
TEST_TYPE_OF(UnsignedInt, unsigned int)
TEST_TYPE_OF(UnsignedLongInt, unsigned long)
TEST_TYPE_OF(UnsignedLongLongInt, unsigned long long)
TEST_TYPE_OF(Float, float)
TEST_TYPE_OF(Double, double)
TEST_TYPE_OF(LongDouble, long double)

#endif
