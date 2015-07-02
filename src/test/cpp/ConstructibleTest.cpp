#include "ConstructibleTest.hpp"
#include "DummyTypes.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(ConstructibleTest);

TYPE_ASSERTION_TEST(ConstructibleTest, isConstructibleWith) {
    AssertThat<TypeParam>::isConstructibleWith();

    this->checkResult("%s should be constructible");
}

SHOULD_SUCCEED(ConstructibleTest, isConstructibleWith, DummyType);
SHOULD_FAIL(ConstructibleTest, isConstructibleWith, ClassWithNoConstructor);
