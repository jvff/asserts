#include "CopyConstructibleTest.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(CopyConstructibleTest);

TYPE_ASSERTION_TEST(CopyConstructibleTest, isCopyConstructible) {
    AssertThat<TypeParam>::isCopyConstructible();
}

SHOULD_SUCCEED(CopyConstructibleTest, isCopyConstructible,
	ClassWithDefaultConstructors,
	ClassWithDefaultCopyConstructor,
	ClassWithCustomCopyConstructor);
SHOULD_FAIL(CopyConstructibleTest, isCopyConstructible,
	ClassWithNoConstructors,
	ClassWithDeletedCopyConstructor,
	ClassWithCustomConstructorButNoCopyConstructor);
