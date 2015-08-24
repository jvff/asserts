#include "MethodTest.hpp"
#include "ValueAssertionMacros.hpp"

static auto constMethod = &DummyClass::constMethod;
static auto nonConstMethod = &DummyClass::nonConstMethod;

VALUE_ASSERTION_TEST_CASE(MethodTest);

VALUE_ASSERTION_TEST(MethodTest, isMethod) {
    assertThat(parameter).isMethod();

    checkResult("Expected %s to be a method");
}

VALUES_SHOULD_SUCCEED(MethodTest, isMethod, constMethod, nonConstMethod);

VALUE_ASSERTION_TEST(MethodTest, isConstMethod) {
    assertThat(parameter).isConstMethod();

    checkResult("Expected method to be const qualified");
}

VALUES_SHOULD_SUCCEED(MethodTest, isConstMethod, constMethod);
VALUES_SHOULD_FAIL(MethodTest, isConstMethod, nonConstMethod);
