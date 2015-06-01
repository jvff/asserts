#include "ClassTest.hpp"

TEST_F(ClassTest, isClassOrStructSucceedsWithClass) {
    AssertThat<DummyClass>::isClassOrStruct();

    shouldSucceed();
}

TEST_F(ClassTest, isClassOrStructSucceedsWithStruct) {
    AssertThat<DummyType>::isClassOrStruct();

    shouldSucceed();
}

TEST_F(ClassTest, isClassOrStructFailsWithUnion) {
    AssertThat<DummyUnion>::isClassOrStruct();

    shouldFail("Type should be a class or a struct");
}
