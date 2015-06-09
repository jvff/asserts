#include "NullTest.hpp"

static const int dummyVariable = 0;
static const void* dummyPointer = &dummyVariable;
static const void* nullPointer = NULL;

VALUE_ASSERTION_TEST(NullTest, isNull) {
    assertThat(parameter).isNull();

    checkResult("Pointer should be NULL");
}

VALUES_SHOULD_SUCCEED(NullTest, isNull, nullPointer);
VALUES_SHOULD_FAIL(NullTest, isNull, dummyPointer);

VALUE_ASSERTION_TEST(NullTest, isNotNull) {
    assertThat(parameter).isNotNull();

    checkResult("Pointer should not be NULL");
}

VALUES_SHOULD_SUCCEED(NullTest, isNotNull, dummyPointer);
VALUES_SHOULD_FAIL(NullTest, isNotNull, nullPointer);
