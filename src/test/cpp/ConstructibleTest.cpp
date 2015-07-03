#include "ConstructibleTest.hpp"
#include "TypeAssertionMacros.hpp"

using std::tuple;

TYPE_ASSERTION_TEST_CASE(ConstructibleTest);

TYPE_ASSERTION_TEST_T(ConstructibleTest, isConstructibleWith, 1N) {
    AssertThat<TypeParam1>::isConstructible(With<TypeParams...>());

    this->checkResult("%s should be constructible");
}

SHOULD_SUCCEED(ConstructibleTest, isConstructibleWith,
	tuple<ClassWithDefaultConstructor>,
	tuple<ClassWithConstructorWithOneIntParameter, int>,
	tuple<ClassWithConstructorWithIntAndDummyParameter, int, DummyType>);
SHOULD_FAIL(ConstructibleTest, isConstructibleWith,
	tuple<ClassWithNoConstructor>,
	tuple<ClassWithDefaultConstructor, int>,
	tuple<ClassWithDefaultConstructor, DummyType>,
	tuple<ClassWithConstructorWithOneIntParameter>,
	tuple<ClassWithConstructorWithOneIntParameter, DummyType>,
	tuple<ClassWithConstructorWithOneIntParameter, int, int>,
	tuple<ClassWithConstructorWithIntAndDummyParameter, DummyType, int>);
