#include "CopyConstructibleTest.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(CopyConstructibleTest);

TYPE_ASSERTION_TEST(CopyConstructibleTest, isCopyConstructible) {
    AssertThat<TypeParam>::isCopyConstructible();

    this->checkResult("%s should be copy constructible");
}

TYPE_ASSERTION_TEST(CopyConstructibleTest, isNotCopyConstructible) {
    AssertThat<TypeParam>::isNotCopyConstructible();

    this->checkResult("%s should not be copy constructible");
}

TYPE_ASSERTION_TESTS_ARE_OPPOSITE(CopyConstructibleTest, isCopyConstructible,
        isNotCopyConstructible);

SHOULD_SUCCEED(CopyConstructibleTest, isCopyConstructible,
        ClassWithDefaultConstructors,
        ClassWithDefaultCopyConstructor,
        ClassWithCustomCopyConstructor,
        ClassWithCustomConstructorButNoCopyConstructor);
SHOULD_FAIL(CopyConstructibleTest, isCopyConstructible,
        ClassWithNoConstructors,
        ClassWithDeletedCopyConstructor);
