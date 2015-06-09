#ifndef NULL_TEST_HPP
#define NULL_TEST_HPP

#include "AbstractValueAssertionTest.hpp"

template <bool shouldSucceed>
class NullTest : public AbstractValueAssertionTest<const void*, shouldSucceed> {
};

#endif
