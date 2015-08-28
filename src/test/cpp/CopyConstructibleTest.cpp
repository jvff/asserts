#include "CopyConstructibleTest.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(CopyConstructibleTest);

TYPE_ASSERTION_TEST(CopyConstructibleTest, isCopyConstructible) {
    AssertThat<TypeParam>::isCopyConstructible();
}

TYPE_ASSERTION_TEST(CopyConstructibleTest, isNotCopyConstructible) {
    AssertThat<TypeParam>::isNotCopyConstructible();
}

TYPE_ASSERTION_TESTS_ARE_OPPOSITE(CopyConstructibleTest, isCopyConstructible,
        isNotCopyConstructible);

SHOULD_SUCCEED(CopyConstructibleTest, isCopyConstructible,
        ClassWithDefaultConstructors,
        ClassWithDefaultCopyConstructor,
        ClassWithCustomCopyConstructor);
SHOULD_FAIL(CopyConstructibleTest, isCopyConstructible,
        ClassWithNoConstructors,
        ClassWithDeletedCopyConstructor,
        ClassWithCustomConstructorButNoCopyConstructor);
