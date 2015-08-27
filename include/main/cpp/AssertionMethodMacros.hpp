#ifndef ASSERTION_METHOD_MACROS_HPP
#define ASSERTION_METHOD_MACROS_HPP

#include "gtest/gtest.h"

#include "AssertionTester.hpp"
#include "FailureMessage.hpp"
#include "Of.hpp"
#include "TypeOf.hpp"
#include "With.hpp"

#define TYPE_ASSERTION(methodName, testCondition) \
    static ASSERTION_BODY_WITH_MESSAGE(methodName, testCondition, \
            FAILURE_MESSAGE_FOR(methodName), TypeOf<T>())

#define TYPE_ASSERTION_WITH_PARAM(methodName, ...) \
    template <typename T2> \
    static ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, (__VA_ARGS__), \
            (const Of<T2>&), \
            FAILURE_MESSAGE_FOR(methodName), TypeOf<T>(), TypeOf<T2>())

#define TYPE_ASSERTION_WITH_PARAMS(methodName, ...) \
    template <typename... Params> \
    static ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, (__VA_ARGS__), \
            (const With<Params...>&), \
            FAILURE_MESSAGE_FOR(methodName), TypeOf<T>())

#define ASSERTION(methodName, testCondition, ...) \
    ASSERTION_BODY_WITH_MESSAGE(methodName, testCondition, \
            FAILURE_MESSAGE_FOR(methodName), __VA_ARGS__)

#define ASSERTION_WITH_PARAM(methodName, testCondition, ...) \
    template <typename T2> \
    ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, testCondition, \
            (const T2& parameter), \
            FAILURE_MESSAGE_FOR(methodName), __VA_ARGS__)

#define ASSERTION_WITH_TYPE_PARAM(methodName, testCondition, ...) \
    template <typename TypeParam> \
    ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, testCondition, \
            (const TypeParam&), \
            FAILURE_MESSAGE_FOR(methodName), __VA_ARGS__)

#define ASSERTION_BODY_WITH_MESSAGE(methodName, testCondition, ...) \
    ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, testCondition, (), \
            __VA_ARGS__)

#define ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, testCondition, \
        parameters, ...) \
    void methodName parameters { \
        AssertionTester::test(testCondition, __VA_ARGS__); \
    }

#define FAILURE_MESSAGE_FOR(MethodName) \
    FailureMessage<MethodName##FailureMessageId>::message

#endif
