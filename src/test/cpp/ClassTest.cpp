#include "ClassTest.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(ClassTest);

TYPE_ASSERTION_TEST(ClassTest, isClassOrStruct) {
    AssertThat<TypeParam>::isClassOrStruct();

    this->checkResult("Type should be a class or a struct");
}

SHOULD_SUCCEED(ClassTest, isClassOrStruct, DummyClass, DummyType);
SHOULD_FAIL(ClassTest, isClassOrStruct, DummyUnion);
