#include "VirtualDestructorTest.hpp"

TEST_F(VirtualDestructorTest, succeedsForSuperClass) {
    AssertThat<SuperClassWithVirtualDestructor>::hasVirtualDestructor();

    shouldSucceed();
}

TEST_F(VirtualDestructorTest, failsForSuperClass) {
    AssertThat<SuperClassWithoutVirtualDestructor>::hasVirtualDestructor();

    shouldFail("Class should have virtual destructor");
}
