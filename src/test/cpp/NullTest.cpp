#include "ValueAssertionMacros.hpp"

static const int dummyVariable = 0;

static const void* dummyPointer = &dummyVariable;
static const void* nullPointer = NULL;

VALUE_ASSERTION_TEST_CASE(NullTest);

VALUE_ASSERTION_TEST(NullTest, isNull) {
    assertThat(parameter).isNull();

    checkResult("Pointer should be NULL");
}

VALUE_ASSERTION_TEST(NullTest, isNotNull) {
    assertThat(parameter).isNotNull();

    checkResult("Pointer should not be NULL");
}

VALUE_ASSERTION_TESTS_ARE_OPPOSITE(NullTest, isNull, isNotNull);

VALUES_SHOULD_SUCCEED(NullTest, isNull, nullPointer);
VALUES_SHOULD_FAIL(NullTest, isNull, dummyPointer);
