#include "MethodTest.hpp"
#include "ValueAssertionMacros.hpp"

static auto constMethod = &DummyClass::constMethod;
static auto nonConstMethod = &DummyClass::nonConstMethod;
static auto dummyObject = DummyClass();

VALUE_ASSERTION_TEST_CASE(MethodTest);

VALUE_ASSERTION_TEST(MethodTest, isMethod) {
    assertThat(parameter).isMethod();

    checkResult("Expected %s to be a method", parameter);
}

VALUES_SHOULD_SUCCEED(MethodTest, isMethod, constMethod, nonConstMethod);
VALUES_SHOULD_FAIL(MethodTest, isMethod, dummyObject);

VALUE_ASSERTION_TEST(MethodTest, isConstMethod) {
    assertThat(parameter).isConstMethod();

    checkResult("Expected method to be const qualified");
}

VALUES_SHOULD_SUCCEED(MethodTest, isConstMethod, constMethod);
VALUES_SHOULD_FAIL(MethodTest, isConstMethod, nonConstMethod);
