#include "ClassTest.hpp"

typedef testing::Types<
    DummyClass,
    DummyType,
    DummyUnion
> Types;

TYPED_TEST_CASE(ClassTest, Types);

SHOULD_SUCCEED(DummyClass);
SHOULD_SUCCEED(DummyType);
SHOULD_FAIL(DummyUnion);

TYPED_TEST(ClassTest, isClassOrStructTest) {
    AssertThat<TypeParam>::isClassOrStruct();

    this->checkResult("Type should be a class or a struct");
}
