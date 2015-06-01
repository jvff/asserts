#include "gtest/gtest.h"

#include "FakeTestReporter.hpp"

#include "asserts.hpp"

class DummyClass {
};

TEST(ClassTest, isClassOrStructSucceedsWithClass) {
    FakeTestReporter::reset();

    AssertThat<DummyClass>::isClassOrStruct();

    EXPECT_TRUE(FakeTestReporter::succeeded);
}
