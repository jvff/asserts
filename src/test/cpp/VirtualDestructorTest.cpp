#include "VirtualDestructorTest.hpp"

TEST_F(VirtualDestructorTest, succeedsForSuperClass) {
    AssertThat<SuperClassWithVirtualDestructor>::hasVirtualDestructor();

    shouldSucceed();
}

TEST_F(VirtualDestructorTest, failsForSuperClass) {
    AssertThat<SuperClassWithoutVirtualDestructor>::hasVirtualDestructor();

    shouldFail("Class should have virtual destructor");
}

TEST_F(VirtualDestructorTest, succeedsForSubClass) {
    AssertThat<SubClassWithVirtualDestructor>::hasVirtualDestructor();

    shouldSucceed();
}

TEST_F(VirtualDestructorTest, failsForSubClass) {
    AssertThat<SubClassWithoutVirtualDestructor>::hasVirtualDestructor();

    shouldFail("Class should have virtual destructor");
}

TEST_F(VirtualDestructorTest, succeedsForSubClassWithMultipleInheritance) {
    AssertThat<SubClassWithMultipleInheritance>::hasVirtualDestructor();

    shouldSucceed();
}
