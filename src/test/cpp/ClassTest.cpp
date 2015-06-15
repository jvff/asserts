#include "ClassTest.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(ClassTest);

TYPE_ASSERTION_TEST(ClassTest, isClassOrStruct) {
    AssertThat<TypeParam>::isClassOrStruct();

    this->checkResult("%s should be a class or a struct");
}

SHOULD_SUCCEED(ClassTest, isClassOrStruct, DummyClass, DummyType);
SHOULD_FAIL(ClassTest, isClassOrStruct, DummyUnion);

TYPE_ASSERTION_TEST_T(ClassTest, isSubClassOf, 2) {
    AssertThat<TypeParam1>::isSubClass(Of<TypeParam2>());

    this->checkResult("%s should be a sub-class of %s", TypeOf<TypeParam2>());
}

SHOULD_SUCCEED(ClassTest, isSubClassOf, tuple<DerivedClass, BaseClass>);
SHOULD_FAIL(ClassTest, isSubClassOf,
        tuple<BaseClass, DerivedClass>,
        tuple<DummyClass, BaseClass>);
