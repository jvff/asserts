#include "TypeAssertionMacros.hpp"
#include "VirtualDestructorTest.hpp"

TYPE_ASSERTION_TEST(VirtualDestructorTest) {
    AssertThat<TypeParam>::hasVirtualDestructor();

    this->checkResult("Class should have virtual destructor");
}

SHOULD_SUCCEED(VirtualDestructorTest,
    SuperClassWithVirtualDestructor,
    SubClassWithVirtualDestructor,
    SubClassWithMultipleInheritance);
SHOULD_FAIL(VirtualDestructorTest,
    SuperClassWithoutVirtualDestructor,
    SuperClassWithNonVirtualDestructor,
    SubClassWithoutVirtualDestructor,
    SubClassWithNonVirtualDestructor);
