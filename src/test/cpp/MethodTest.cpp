#include "MethodTest.hpp"

static auto constMethod = &DummyClass::constMethod;
static auto nonConstMethod = &DummyClass::nonConstMethod;
static auto dummyObject = DummyClass();

template <typename MethodType, typename Signature>
static MethodAndSignaturePair<MethodType, Signature> pair(
        const MethodType& method, const WithSignature<Signature>&) {
    return MethodAndSignaturePair<MethodType, Signature>(method);
}

VALUE_ASSERTION_TEST_CASE(MethodTest);

VALUE_ASSERTION_TEST(MethodTest, isMethod) {
    assertThat(parameter).isMethod();

    checkResult("Expected %s to be a method", parameter);
}

VALUES_SHOULD_SUCCEED(MethodTest, isMethod, constMethod, nonConstMethod);
VALUES_SHOULD_FAIL(MethodTest, isMethod, dummyObject);

VALUE_ASSERTION_TEST(MethodTest, isConstMethod) {
    assertThat(parameter).isConstMethod();

    checkResult("Expected %s to be a const qualified method", parameter);
}

VALUES_SHOULD_SUCCEED(MethodTest, isConstMethod, constMethod);
VALUES_SHOULD_FAIL(MethodTest, isConstMethod, nonConstMethod, dummyObject);

VALUE_ASSERTION_TEST(MethodTest, isMethodWithSignature) {
    using Signature = typename ParamType::Signature;

    const auto& method = parameter.method;

    assertThat(method).isMethod(WithSignature<Signature>());

    checkResult("Expected %s to be a method with signature %s", method,
            TypeOf<Signature>());
}

VALUES_SHOULD_SUCCEED(MethodTest, isMethodWithSignature,
        pair(constMethod, WithSignature<void()>()),
        pair(nonConstMethod, WithSignature<void()>()));
VALUES_SHOULD_FAIL(MethodTest, isMethodWithSignature,
        pair(dummyObject, WithSignature<void()>()),
        pair(constMethod, WithSignature<int()>()),
        pair(nonConstMethod, WithSignature<void(int)>()));
