#include "AssertionsSpecificForTest.hpp"

TEST_PARAMETERS(AssertionsSpecificForTest,
        DummyType(), &DummyClass::method, &DummyClass::constMethod,
        150, 30.f, -59.0, (long double)0.0);

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

TEST_CP(AssertionsSpecificForTest, isCopyConstructible) {
    using ClassType = AssertionsSpecificFor<ParamType>;

    EXPECT_TRUE((std::is_copy_constructible<ClassType>::value));
}

TEST_CP(AssertionsSpecificForTest, hasSubject) {
    const ParamType& subject = parameter;
    FakeAssertionsSpecificFor<ParamType> assertionsFor(subject);

    EXPECT_EQ(&subject, &assertionsFor.getSubject());
}

TEST_CP(AssertionsSpecificForTest, copyConstructorPreservesSubjectReference) {
    const ParamType& subject = parameter;
    AssertionsSpecificFor<ParamType> original(subject);
    FakeAssertionsSpecificFor<ParamType> copy(original);

    EXPECT_EQ(&subject, &copy.getSubject());
}
