#include "ConstMethodTest.hpp"
#include "ValueAssertionMacros.hpp"

static auto constMethod = &DummyClass::constMethod;
static auto nonConstMethod = &DummyClass::nonConstMethod;

VALUE_ASSERTION_TEST_CASE(ConstMethodTest);

VALUE_ASSERTION_TEST(ConstMethodTest, isConstMethod) {
    assertThat(parameter).isConstMethod();

    checkResult("Expected method to be const qualified");
}

VALUES_SHOULD_SUCCEED(ConstMethodTest, isConstMethod, constMethod);
VALUES_SHOULD_FAIL(ConstMethodTest, isConstMethod, nonConstMethod);
