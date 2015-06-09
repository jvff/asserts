#include "NullTest.hpp"

TEST_F(NullTest, isNullSucceeds) {
    const void* pointer = NULL;

    assertThat(pointer).isNull();

    shouldSucceed();
}

TEST_F(NullTest, isNullFails) {
    const int dummyVariable = 0;
    const void* pointer = (const void*)&dummyVariable;

    assertThat(pointer).isNull();

    shouldFail("Pointer should be NULL");
}

TEST_F(NullTest, isNotNullSucceeds) {
    const int dummyVariable = 0;
    const void* pointer = (const void*)&dummyVariable;

    assertThat(pointer).isNotNull();

    shouldSucceed();
}
