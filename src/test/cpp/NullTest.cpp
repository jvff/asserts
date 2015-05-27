#include "gtest/gtest.h"

#include "FakeTestReporter.hpp"

#include "asserts.hpp"

TEST(NullTest, succeed) {
    const void* pointer = NULL;

    FakeTestReporter::reset();

    assertThat(pointer).isNull();

    EXPECT_TRUE(FakeTestReporter::succeeded);
}
