#include "ConstructibleTest.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(ConstructibleTest);

TYPE_ASSERTION_TEST_T(ConstructibleTest, isConstructibleWith, 1N) {
    AssertThat<TypeParam1>::isConstructible(With<TypeParams...>());

    this->checkResult("%s should be constructible");
}

SHOULD_SUCCEED(ConstructibleTest, isConstructibleWith,
	Pack<ClassWithDefaultConstructor>,
	Pack<ClassWithConstructorWithOneIntParameter, int>,
	Pack<ClassWithConstructorWithIntAndDummyParameter, int, DummyType>);
SHOULD_FAIL(ConstructibleTest, isConstructibleWith,
	Pack<ClassWithNoConstructor>,
	Pack<ClassWithDefaultConstructor, int>,
	Pack<ClassWithDefaultConstructor, DummyType>,
	Pack<ClassWithConstructorWithOneIntParameter>,
	Pack<ClassWithConstructorWithOneIntParameter, DummyType>,
	Pack<ClassWithConstructorWithOneIntParameter, int, int>,
	Pack<ClassWithConstructorWithIntAndDummyParameter, DummyType, int>);
