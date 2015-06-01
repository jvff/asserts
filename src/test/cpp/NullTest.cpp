#include "NullTest.hpp"

TEST_F(NullTest, succeed) {
    const void* pointer = NULL;

    assertThat(pointer).isNull();

    shouldSucceed();
}

TEST_F(NullTest, fail) {
    const int dummyVariable = 0;
    const void* pointer = (const void*)&dummyVariable;

    assertThat(pointer).isNull();

    shouldFail("Pointer should be NULL");
}
