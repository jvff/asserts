#include "gtest/gtest.h"

#include "FakeTestReporter.hpp"

#include "asserts.hpp"

TEST(NullTest, succeed) {
    const void* pointer = NULL;

    FakeTestReporter::reset();

    assertThat(pointer).isNull();

    EXPECT_TRUE(FakeTestReporter::succeeded);
}

TEST(NullTest, fail) {
    const int dummyVariable = 0;
    const void* pointer = (const void*)&dummyVariable;

    FakeTestReporter::reset();

    assertThat(pointer).isNull();

    EXPECT_TRUE(FakeTestReporter::failed);
    EXPECT_EQ("Pointer should be NULL", FakeTestReporter::failureMessage.get());
}
