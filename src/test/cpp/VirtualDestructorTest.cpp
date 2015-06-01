#include "VirtualDestructorTest.hpp"

TEST_F(VirtualDestructorTest, succeedsForSuperClass) {
    AssertThat<SuperClassWithVirtualDestructor>::hasVirtualDestructor();

    shouldSucceed();
}
