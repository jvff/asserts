#include "TypeAssertionMacros.hpp"
#include "VirtualDestructorTest.hpp"

TYPE_ASSERTION_TEST_CASE(VirtualDestructorTest);

TYPE_ASSERTION_TEST(VirtualDestructorTest, hasVirtualDestructor) {
    AssertThat<TypeParam>::hasVirtualDestructor();

    this->checkResult("%s should have virtual destructor");
}

SHOULD_SUCCEED(VirtualDestructorTest, hasVirtualDestructor,
    SuperClassWithVirtualDestructor,
    SubClassWithVirtualDestructor,
    SubClassWithMultipleInheritance);
SHOULD_FAIL(VirtualDestructorTest, hasVirtualDestructor,
    SuperClassWithoutVirtualDestructor,
    SuperClassWithNonVirtualDestructor,
    SubClassWithoutVirtualDestructor,
    SubClassWithNonVirtualDestructor);
