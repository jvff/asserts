#include "DummyTypes.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(SameTypeTest);

TYPE_ASSERTION_TEST_T(SameTypeTest, isTheSameAs, 2) {
    AssertThat<TypeParam1>::isTheSame(As<TypeParam2>());

    this->checkResult("%s should be the same type as %s", TypeOf<TypeParam2>());
}

SHOULD_SUCCEED(SameTypeTest, isTheSameAs,
        Pack<bool, bool>,
        Pack<char, char>,
        Pack<signed char, signed char>,
        Pack<unsigned char, unsigned char>,
        Pack<short, signed short int>,
        Pack<unsigned long, unsigned long int>,
        Pack<DummyType, DummyTypes<0> >);
SHOULD_FAIL(SameTypeTest, isTheSameAs,
        Pack<bool, int>,
        Pack<char, unsigned char>,
        Pack<char, signed char>,
        Pack<signed char, char>,
        Pack<unsigned char, char>,
        Pack<unsigned int, int>,
        Pack<DummyType, DummyTypes<1> >,
        Pack<DummyType, int>,
        Pack<int, DummyType>);
