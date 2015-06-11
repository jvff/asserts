#ifndef VALUE_ASSERTION_MACROS_HPP
#define VALUE_ASSERTION_MACROS_HPP

#include "gtest/gtest.h"

#include "ValueAssertionTestRegistration.hpp"

#define BOOL_VALUE_OF_succeeds true
#define BOOL_VALUE_OF_fails false

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
template <bool shouldSucceed> \
class AbstractParent : public TestCase<shouldSucceed> { \
protected: \
    typedef typename TestCase<shouldSucceed>::ParamType ParamType; \
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
    using TestCase<shouldSucceed>::checkResult; \
}

#define MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, SuperClass, \
        TestType) \
    MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS_CALLED( \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
            SuperClass, BOOL_VALUE_OF_##TestType) \

#define MAKE_VALUE_ASSERTION_TEST_CHILD_CLASS_CALLED(ClassName, SuperClass, \
        ShouldSucceed) \
class ClassName : public SuperClass<ShouldSucceed> { \
protected: \
    typedef typename SuperClass<ShouldSucceed>::ParamType ParamType; \
\
public: \
    ClassName(ParamType& testParameter) : \
            SuperClass<ShouldSucceed>(testParameter) { \
    } \
\
protected: \
    using SuperClass<ShouldSucceed>::TestBody; \
}

#define START_VALUE_ASSERTION_TEST_BODY(AbstractParent) \
template <bool shouldSucceed> \
void AbstractParent<shouldSucceed>::TestBody()

#define VALUES_SHOULD_SUCCEED(TestCase, TestName, ...) \
    REGISTER_VALUE_ASSERTION_TEST(TestCase, TestName, succeeds, \
            __VA_ARGS__)

#define VALUES_SHOULD_FAIL(TestCase, TestName, ...) \
    REGISTER_VALUE_ASSERTION_TEST(TestCase, TestName, fails, \
            __VA_ARGS__)

#define REGISTER_VALUE_ASSERTION_TEST(TestCase, TestName, TestType, \
        Parameters...) \
    bool gtest_##TestCase##_##TestName##_##TestType##_registered_ \
            GTEST_ATTRIBUTE_UNUSED_ = \
        ::testing::internal::ValueAssertionTestRegistration<TestCase, \
                GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
                BOOL_VALUE_OF_##TestType> \
                    ::Register(#TestCase "." #TestName, #TestType, \
                            #Parameters, Parameters)

#endif
