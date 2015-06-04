#ifndef CLASS_TEST_HPP
#define CLASS_TEST_HPP

#include "AbstractTypeAssertionTest.hpp"
#include "DummyTypes.hpp"

template <typename T, bool shouldSucceed>
class ClassTest : public AbstractTypeAssertionTest<T, shouldSucceed> {
};

class DummyClass {
};

union DummyUnion {
};

#endif
