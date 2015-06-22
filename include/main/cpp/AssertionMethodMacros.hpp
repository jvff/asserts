#ifndef ASSERTION_METHOD_MACROS_HPP
#define ASSERTION_METHOD_MACROS_HPP

#define TYPE_ASSERTION(methodName, testCondition) \
    static ASSERTION_BODY_WITH_MESSAGE(methodName, testCondition, \
            methodName##FailureMessage, TypeOf<T>()) \
    ASSERTION_MESSAGE_DECLARATION(methodName)

#define TYPE_ASSERTION_WITH_PARAM(methodName, ...) \
    template <typename T2> \
    static ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, (__VA_ARGS__), \
            (const Of<T2>&), \
            methodName##FailureMessage, TypeOf<T>(), TypeOf<T2>()) \
    ASSERTION_MESSAGE_DECLARATION(methodName)

#define ASSERTION(methodName, testCondition) \
    ASSERTION_BODY_WITH_MESSAGE(methodName, testCondition, \
            methodName##FailureMessage) \
    ASSERTION_MESSAGE_DECLARATION(methodName)

#define ASSERTION_WITH_PARAM(methodName, testCondition, ...) \
    template <typename T2> \
    ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, testCondition, \
            (const T2& parameter), \
            methodName##FailureMessage, __VA_ARGS__) \
    ASSERTION_MESSAGE_DECLARATION(methodName)

#define ASSERTION_BODY_WITH_MESSAGE(methodName, testCondition, ...) \
    ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, testCondition, (), \
            __VA_ARGS__)

#define ASSERTION_BODY_WITH_PARAMS_AND_MESSAGE(methodName, testCondition, \
        parameters, ...) \
    void methodName parameters { \
        test(testCondition, __VA_ARGS__); \
    }

#define ASSERTION_MESSAGE_DECLARATION(methodName) \
private: static const std::string methodName##FailureMessage; \
public:

#endif
