#include "AssertionsSpecificForTest.hpp"

TEST_PARAMETERS(AssertionsSpecificForTest,
        DummyType(), &DummyClass::method, &DummyClass::constMethod);

TEST_CP(AssertionsSpecificForTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<AssertionsSpecificFor<ParamType> >::value));
}

TEST_CP(AssertionsSpecificForTest, isSubClassOfCommonAssertions) {
    typedef CommonAssertions<ParamType> superClass;
    typedef AssertionsSpecificFor<ParamType> subClass;

    EXPECT_TRUE((std::is_base_of<superClass, subClass>::value));
}

TEST_CP(AssertionsSpecificForTest, isConstructibleWithParameter) {
    using ClassType = AssertionsSpecificFor<ParamType>;

    EXPECT_TRUE((std::is_constructible<ClassType, ParamType>::value));
}

TEST_CP(AssertionsSpecificForTest, isntConstructibleWithoutParameters) {
    using ClassType = AssertionsSpecificFor<ParamType>;

    EXPECT_FALSE((std::is_constructible<ClassType>::value));
}
