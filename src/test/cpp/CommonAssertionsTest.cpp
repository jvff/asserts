#include <type_traits>

#include "CommonAssertionsTest.hpp"

TEST_F(CommonAssertionsTest, classExists) {
    using DummyCommonAssertions = CommonAssertions<DummyType>;

    EXPECT_TRUE((std::is_class<DummyCommonAssertions>::value));
}

TEST_F(CommonAssertionsTest, hasConstructorWithParameter) {
    using ClassType = CommonAssertions<DummyType>;
    using Parameter = DummyType;

    EXPECT_TRUE((std::is_constructible<ClassType, Parameter>::value));
}

TEST_F(CommonAssertionsTest, subjectIsProperlySet) {
    const DummyType subject;
    FakeCommonAssertions<DummyType> assertion(subject);

    EXPECT_EQ(&subject, &assertion.getSubject());
}
