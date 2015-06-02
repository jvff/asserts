#ifndef VIRTUAL_DESTRUCTOR_TEST_HPP
#define VIRTUAL_DESTRUCTOR_TEST_HPP

#include "AbstractAssertionTest.hpp"

template <typename T>
class VirtualDestructorTest : public AbstractAssertionTest {
};

template <typename T>
class Should {
public:
    static const bool succeed;
};

#define SHOULD_SUCCEED(type) \
template <> \
const bool Should<type>::succeed = true

#define SHOULD_FAIL(type) \
template <> \
const bool Should<type>::succeed = false

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
