#include "gtest/gtest.h"

#include "DummyTypes.hpp"
#include "FakeTestReporter.hpp"

#include "asserts.hpp"

class DummyClass {
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
