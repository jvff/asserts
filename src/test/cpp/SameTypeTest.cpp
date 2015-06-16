#include <tuple>

#include "DummyTypes.hpp"
#include "TypeAssertionMacros.hpp"

using std::tuple;

TYPE_ASSERTION_TEST_CASE(SameTypeTest);

TYPE_ASSERTION_TEST_T(SameTypeTest, isTheSameAs, 2) {
    AssertThat<TypeParam1>::isTheSame(As<TypeParam2>());

    this->checkResult("%s should be the same type as %s", TypeOf<TypeParam2>());
}

SHOULD_SUCCEED(SameTypeTest, isTheSameAs,
        tuple<bool, bool>,
        tuple<char, char>,
        tuple<signed char, signed char>,
        tuple<unsigned char, unsigned char>,
        tuple<short, signed short int>,
        tuple<unsigned long, unsigned long int>,
        tuple<DummyType, DummyTypes<0> >);
SHOULD_FAIL(SameTypeTest, isTheSameAs,
        tuple<bool, int>,
        tuple<char, unsigned char>,
        tuple<char, signed char>,
        tuple<signed char, char>,
        tuple<unsigned char, char>,
        tuple<unsigned int, int>,
        tuple<DummyType, DummyTypes<1> >,
        tuple<DummyType, int>,
        tuple<int, DummyType>);
