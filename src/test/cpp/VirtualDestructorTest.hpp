#ifndef VIRTUAL_DESTRUCTOR_TEST_HPP
#define VIRTUAL_DESTRUCTOR_TEST_HPP

#include "AbstractAssertionTest.hpp"

class VirtualDestructorTest : public AbstractAssertionTest {
};

class SuperClassWithVirtualDestructor {
    virtual ~SuperClassWithVirtualDestructor() = 0;
};

class SuperClassWithoutVirtualDestructor {
};

class SuperClassWithNonVirtualDestructor {
    ~SuperClassWithNonVirtualDestructor() {
    }
};

class SubClassWithVirtualDestructor : public SuperClassWithVirtualDestructor {
    ~SubClassWithVirtualDestructor() = 0;
};

class SubClassWithoutVirtualDestructor :
        public SuperClassWithoutVirtualDestructor {
};

class SubClassWithNonVirtualDestructor :
        public SuperClassWithNonVirtualDestructor {
};

class SubClassWithMultipleInheritance : public SubClassWithVirtualDestructor,
        public SubClassWithoutVirtualDestructor {
    ~SubClassWithMultipleInheritance() = 0;
};

#endif
