#include "gtest/gtest.h"

#include "DummyTypes.hpp"
#include "FakeTestReporter.hpp"

#include "asserts.hpp"

class DummyClass {
};

union DummyUnion {
};

TEST(ClassTest, isClassOrStructSucceedsWithClass) {
    FakeTestReporter::reset();

    AssertThat<DummyClass>::isClassOrStruct();

    EXPECT_TRUE(FakeTestReporter::succeeded);
}

TEST(ClassTest, isClassOrStructSucceedsWithStruct) {
    FakeTestReporter::reset();

    AssertThat<DummyType>::isClassOrStruct();

    EXPECT_TRUE(FakeTestReporter::succeeded);
}

TEST(ClassTest, isClassOrStructFailsWithUnion) {
    FakeTestReporter::reset();

    AssertThat<DummyUnion>::isClassOrStruct();

    EXPECT_TRUE(FakeTestReporter::failed);
    EXPECT_EQ("Type should be a class or a struct",
            FakeTestReporter::failureMessage.get());
}
