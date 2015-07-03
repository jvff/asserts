#include "ConstructibleTest.hpp"
#include "DummyTypes.hpp"
#include "TypeAssertionMacros.hpp"

using std::tuple;

TYPE_ASSERTION_TEST_CASE(ConstructibleTest);

TYPE_ASSERTION_TEST_T(ConstructibleTest, isConstructibleWith, 1N) {
    AssertThat<TypeParam1>::isConstructible(With<TypeParams...>());

    this->checkResult("%s should be constructible");
}

SHOULD_SUCCEED(ConstructibleTest, isConstructibleWith, tuple<DummyType>);
SHOULD_FAIL(ConstructibleTest, isConstructibleWith,
	tuple<ClassWithNoConstructor>);
