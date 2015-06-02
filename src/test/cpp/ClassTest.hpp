#ifndef CLASS_TEST_HPP
#define CLASS_TEST_HPP

#include "AbstractTypeAssertionTest.hpp"
#include "DummyTypes.hpp"

template <typename T>
class ClassTest : public AbstractTypeAssertionTest<T> {
};

class DummyClass {
};

union DummyUnion {
};

#endif
