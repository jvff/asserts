#include <tuple>

#include "TypeAssertionMacros.hpp"

using std::tuple;

TYPE_ASSERTION_TEST_CASE(SameTypeTest);

TYPE_ASSERTION_TEST_T(SameTypeTest, isTheSameAs, 2) {
    AssertThat<TypeParam1>::isTheSame(As<TypeParam2>());

    this->checkResult("%s should be the same type as %s", TypeOf<TypeParam2>());
}

SHOULD_SUCCEED(SameTypeTest, isTheSameAs, tuple<bool, bool>);
SHOULD_FAIL(SameTypeTest, isTheSameAs, tuple<bool, int>);
