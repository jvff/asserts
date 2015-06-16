#ifndef VALUE_ASSERTION_MACROS_HPP
#define VALUE_ASSERTION_MACROS_HPP

#include "gtest/gtest.h"

#include "AbstractValueAssertionTest.hpp"
#include "ValueAssertionTestRegistration.hpp"

#define BOOL_VALUE_OF_succeeds true
#define BOOL_VALUE_OF_fails false

#define VALUE_ASSERTION_TEST_CASE(TestCase) \
template <typename parameterType, bool shouldSucceed> \
class TestCase : \
    public AbstractValueAssertionTest<parameterType, shouldSucceed> { \
}

#define VALUE_ASSERTION_TEST(TestCase, TestName) \
   MAKE_VALUE_ASSERTION_TEST_WITH_PARENT(TestCase, TestName, \
           GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, abstractParent))

#define MAKE_VALUE_ASSERTION_TEST_WITH_PARENT(TestCase, TestName, \
        AbstractParent) \
    MAKE_VALUE_ASSERTION_TEST_PARENT_CLASS(TestCase, AbstractParent); \
    MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, AbstractParent, \
            succeeds); \
    MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, AbstractParent, \
            fails); \
    START_VALUE_ASSERTION_TEST_BODY(AbstractParent)

#define MAKE_VALUE_ASSERTION_TEST_PARENT_CLASS(TestCase, AbstractParent) \
template <typename parameterType, bool shouldSucceed> \
class AbstractParent : public TestCase<parameterType, shouldSucceed> { \
protected: \
    typedef parameterType ParamType; \
\
private: \
    ParamType& parameter; \
\
protected: \
    AbstractParent(ParamType& testParameter) : parameter(testParameter) { \
    } \
\
    virtual void TestBody(); \
\
private: \
    using TestCase<parameterType, shouldSucceed>::checkResult; \
}

#define MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, SuperClass, \
        TestType) \
    MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS_CALLED( \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
            SuperClass, BOOL_VALUE_OF_##TestType) \

#define MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS_CALLED(ClassName, SuperClass, \
        ShouldSucceed) \
template <typename parameterType> \
class ClassName : public SuperClass<parameterType, ShouldSucceed> { \
protected: \
    typedef parameterType ParamType; \
\
public: \
    ClassName(ParamType& testParameter) : \
            SuperClass<parameterType, ShouldSucceed>(testParameter) { \
    } \
\
protected: \
    using SuperClass<parameterType, ShouldSucceed>::TestBody; \
}

#define START_VALUE_ASSERTION_TEST_BODY(AbstractParent) \
template <typename parameterType, bool shouldSucceed> \
void AbstractParent<parameterType, shouldSucceed>::TestBody()

#define VALUES_SHOULD_SUCCEED(TestCase, TestName, ...) \
    REGISTER_VALUE_ASSERTION_TEST(TestCase, TestName, succeeds, \
            __VA_ARGS__)

#define VALUES_SHOULD_FAIL(TestCase, TestName, ...) \
    REGISTER_VALUE_ASSERTION_TEST(TestCase, TestName, fails, \
            __VA_ARGS__)

#define REGISTER_VALUE_ASSERTION_TEST(TestCase, TestName, TestType, ...) \
    bool gtest_##TestCase##_##TestName##_##TestType##_registered_ \
            GTEST_ATTRIBUTE_UNUSED_ = \
        ::testing::internal::ValueAssertionTestRegistration<TestCase, \
                GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
                BOOL_VALUE_OF_##TestType> \
                    ::Register(#TestCase "." #TestName, #TestType, \
                            #__VA_ARGS__, __VA_ARGS__)

#endif
