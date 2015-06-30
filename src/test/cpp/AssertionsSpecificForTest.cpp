#include <type_traits>

#include "gtest/gtest.h"

#include "AssertionsSpecificFor.hpp"

#include "DummyTypes.hpp"

TEST(AssertionsSpecificForTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<AssertionsSpecificFor<DummyType> >::value));
}

TEST(AssertionsSpecificForTest, isSubClassOfCommonAssertions) {
    typedef CommonAssertions superClass;
    typedef AssertionsSpecificFor<DummyType> subClass;

    EXPECT_TRUE((std::is_base_of<superClass, subClass>::value));
}
