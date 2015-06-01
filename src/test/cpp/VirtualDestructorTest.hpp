#ifndef VIRTUAL_DESTRUCTOR_TEST_HPP
#define VIRTUAL_DESTRUCTOR_TEST_HPP

#include "AbstractAssertionTest.hpp"

class VirtualDestructorTest : public AbstractAssertionTest {
};

class SuperClassWithVirtualDestructor {
    virtual ~SuperClassWithVirtualDestructor() = 0;
};

#endif
