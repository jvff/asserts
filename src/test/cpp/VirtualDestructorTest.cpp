#include "VirtualDestructorTest.hpp"

typedef testing::Types<
    SuperClassWithVirtualDestructor,
    SuperClassWithoutVirtualDestructor,
    SuperClassWithNonVirtualDestructor,
    SubClassWithVirtualDestructor,
    SubClassWithoutVirtualDestructor,
    SubClassWithNonVirtualDestructor,
    SubClassWithMultipleInheritance
> Types;

TYPED_TEST_CASE(VirtualDestructorTest, Types);

SHOULD_SUCCEED(SuperClassWithVirtualDestructor);
SHOULD_SUCCEED(SubClassWithVirtualDestructor);
SHOULD_SUCCEED(SubClassWithMultipleInheritance);
SHOULD_FAIL(SuperClassWithoutVirtualDestructor);
SHOULD_FAIL(SuperClassWithNonVirtualDestructor);
SHOULD_FAIL(SubClassWithoutVirtualDestructor);
SHOULD_FAIL(SubClassWithNonVirtualDestructor);

TYPED_TEST(VirtualDestructorTest, test) {
    AssertThat<TypeParam>::hasVirtualDestructor();

    this->checkResult("Class should have virtual destructor");
}
