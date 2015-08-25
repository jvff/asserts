#include "AssertionsSpecificForTest.hpp"

using MethodType = decltype(&DummyClass::method);
using ConstMethodType = decltype(&DummyClass::constMethod);

using TypesToTest = testing::Types<DummyType, MethodType, ConstMethodType>;
TYPED_TEST_CASE(AssertionsSpecificForTest, TypesToTest);

TYPED_TEST(AssertionsSpecificForTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<AssertionsSpecificFor<TypeParam> >::value));
}

TYPED_TEST(AssertionsSpecificForTest, isSubClassOfCommonAssertions) {
    typedef CommonAssertions<TypeParam> superClass;
    typedef AssertionsSpecificFor<TypeParam> subClass;

    EXPECT_TRUE((std::is_base_of<superClass, subClass>::value));
}
