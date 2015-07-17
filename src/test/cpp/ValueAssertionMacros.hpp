#ifndef VALUE_ASSERTION_MACROS_HPP
#define VALUE_ASSERTION_MACROS_HPP

#include "gtest/gtest.h"

#include "AbstractValueAssertionTest.hpp"
#include "OppositeValueAssertionTestTo.hpp"
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
    const ParamType& parameter; \
\
protected: \
    AbstractParent(const ParamType& testParameter) : parameter(testParameter) { \
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
    ClassName(const ParamType& testParameter) : \
            SuperClass<parameterType, ShouldSucceed>(testParameter) { \
    } \
\
protected: \
    using SuperClass<parameterType, ShouldSucceed>::TestBody; \
}

#define START_VALUE_ASSERTION_TEST_BODY(AbstractParent) \
template <typename parameterType, bool shouldSucceed> \
void AbstractParent<parameterType, shouldSucceed>::TestBody()

#define VALUE_ASSERTION_TESTS_ARE_OPPOSITE(TestCase, NormalTestName, \
        OppositeTestName) \
    MAKE_OPPOSITE_VALUE_ASSERTION_TEST(TestCase, OppositeTestName, \
        GTEST_TEST_CLASS_NAME_(TestCase##_##NormalTestName, abstractParent), \
        GTEST_TEST_CLASS_NAME_(TestCase##_##OppositeTestName, succeeds), \
        GTEST_TEST_CLASS_NAME_(TestCase##_##OppositeTestName, fails))

#define MAKE_OPPOSITE_VALUE_ASSERTION_TEST(TestCase, OppositeTestName, \
        AbstractParent, SucceedsClass, FailsClass) \
    SPECIALIZE_OPPOSITE_VALUE_ASSERTION_TEST(TestCase, AbstractParent, \
            SucceedsClass, FailsClass); \
    DECLARE_OPPOSITE_VALUE_ASSERTION_TEST_NAME(TestCase, OppositeTestName, \
            AbstractParent)

#define SPECIALIZE_OPPOSITE_VALUE_ASSERTION_TEST(TestCase, AbstractParent, \
        SucceedsClass, FailsClass) \
template <> \
struct OppositeValueAssertionTestTo<TestCase, AbstractParent> { \
    template <typename parameterType> \
    using TestClass_succeeds = SucceedsClass<parameterType>; \
\
    template <typename parameterType> \
    using TestClass_fails = FailsClass<parameterType>; \
\
    static const char* TestCaseName; \
}

#define DECLARE_OPPOSITE_VALUE_ASSERTION_TEST_NAME(TestCase, OppositeTestName, \
        AbstractParent) \
const char* OppositeValueAssertionTestTo<TestCase, AbstractParent> \
        ::TestCaseName = #TestCase "." #OppositeTestName

#define VALUES_SHOULD_SUCCEED(TestCase, TestName, ...) \
    REGISTER_VALUE_ASSERTION_TESTS(TestCase, TestName, succeeds, fails, \
            __VA_ARGS__)

#define VALUES_SHOULD_FAIL(TestCase, TestName, ...) \
    REGISTER_VALUE_ASSERTION_TESTS(TestCase, TestName, fails, succeeds, \
            __VA_ARGS__)

#define REGISTER_VALUE_ASSERTION_TESTS(TestCase, TestName, TestType, \
        OppositeTestType, ...) \
    REGISTER_MAIN_VALUE_ASSERTION_TEST(TestCase, TestName, TestType, \
            __VA_ARGS__); \
    REGISTER_OPPOSITE_VALUE_ASSERTION_TEST(TestCase, TestName, \
            OppositeTestType, \
            OppositeValueAssertionTest_##TestCase##_##TestName, __VA_ARGS__)

#define REGISTER_MAIN_VALUE_ASSERTION_TEST(TestCase, TestName, TestType, ...) \
    REGISTER_VALUE_ASSERTION_TEST(TestCase, #TestCase "." #TestName, TestName, \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), TestType, \
            __VA_ARGS__)

#define REGISTER_OPPOSITE_VALUE_ASSERTION_TEST(TestCase, TestName, TestType, \
        OppositeTestName, ...) \
    DEFINE_OPPOSITE_VALUE_ASSERTION_TEST_NAME(TestCase, TestName, \
            OppositeTestName); \
    REGISTER_VALUE_ASSERTION_TEST(TestCase, OppositeTestName::TestCaseName, \
            TestName##_opposite, OppositeTestName::TestClass_##TestType, \
            TestType, __VA_ARGS__)

#define DEFINE_OPPOSITE_VALUE_ASSERTION_TEST_NAME(TestCase, TestName, \
        OppositeTestName) \
    using OppositeTestName = OppositeValueAssertionTestTo<TestCase, \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, abstractParent)>

#define REGISTER_VALUE_ASSERTION_TEST(TestCase, TestCaseName, TestName, \
        TestClass, TestType, ...) \
    bool gtest_##TestCase##_##TestName##_##TestType##_registered_ \
            GTEST_ATTRIBUTE_UNUSED_ = \
        ::testing::internal::ValueAssertionTestRegistration<TestCase, \
                TestClass, BOOL_VALUE_OF_##TestType> \
                    ::Register(TestCaseName, #TestType, #__VA_ARGS__, \
                            __VA_ARGS__)

#endif
