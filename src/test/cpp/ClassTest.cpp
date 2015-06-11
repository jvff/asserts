#include "ClassTest.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST(ClassTest) {
    AssertThat<TypeParam>::isClassOrStruct();

    this->checkResult("Type should be a class or a struct");
}

SHOULD_SUCCEED(ClassTest, DummyClass, DummyType);
SHOULD_FAIL(ClassTest, DummyUnion);
