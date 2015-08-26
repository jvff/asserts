#include "gtest/gtest.h"

#include "asserts.hpp"

#include "DummyTypes.hpp"
#include "FakeAssertThat.hpp"

TEST(AssertThatTest, classExists) {
    EXPECT_TRUE((std::is_class<AssertThat<DummyType> >::value));
}

TEST(AssertThatTest, hasSuperClass) {
    typedef AssertThat<DummyType> subClass;
    typedef AssertionsSpecificFor<DummyType> superClass;

    EXPECT_TRUE((std::is_base_of<superClass, subClass>::value));
}

TEST(AssertThatTest, hasConstructorWithParameter) {
    typedef AssertThat<DummyType> type;
    typedef const DummyType& parameter;

    EXPECT_TRUE((std::is_constructible<type, parameter>::value));
}

TEST(AssertThatTest, hasCopyConstructor) {
    EXPECT_TRUE((std::is_copy_constructible<AssertThat<DummyType> >::value));
}

TEST(AssertThatTest, hasNoOtherConstructor) {
    typedef AssertThat<DummyType> type;

    EXPECT_FALSE((std::is_default_constructible<type>::value));
    EXPECT_FALSE((std::is_move_constructible<type>::value));
}

TEST(AssertThatTest, subjectIsProperlySet) {
    const DummyType subject;
    FakeAssertThat<DummyType> assertion(subject);

    EXPECT_EQ(&subject, &assertion.getSubject());
}

TEST(AssertThatTest, subjectIsPreservedByCopyConstructor) {
    const DummyType subject;
    AssertThat<DummyType> original(subject);
    FakeAssertThat<DummyType> copy(original);

    EXPECT_EQ(&subject, &copy.getSubject());
}

TEST(AssertThatTest, auxiliaryFunctionExists) {
    const DummyType parameter;
    const DummyType& parameterReference = parameter;

    typedef AssertThat<DummyType> type;
    typedef decltype(assertThat(parameterReference)) returnType;

    EXPECT_TRUE((std::is_same<type, returnType>::value));
}

TEST(AssertThatTest, subjectIsProperlySetByHelperFunction) {
    const DummyType subject;
    const auto& assertion = assertThat(subject);
    FakeAssertThat<DummyType> fakeAssertion(assertion);

    EXPECT_EQ(&subject, &fakeAssertion.getSubject());
}
