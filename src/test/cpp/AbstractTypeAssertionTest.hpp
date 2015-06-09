#ifndef ABSTRACT_TYPE_ASSERTION_TEST_HPP
#define ABSTRACT_TYPE_ASSERTION_TEST_HPP

#include "AbstractSimpleAssertionTest.hpp"
#include "TypeAssertionMacros.hpp"

template <typename T, bool shouldTSucceed>
class AbstractTypeAssertionTest :
        public AbstractSimpleAssertionTest<shouldTSucceed> {
};

#endif
