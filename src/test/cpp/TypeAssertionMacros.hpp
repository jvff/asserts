#ifndef TYPE_ASSERTION_MACROS_HPP
#define TYPE_ASSERTION_MACROS_HPP

#include "gtest/gtest.h"

#include "AbstractTypeAssertionTest.hpp"
#include "TypeAssertionTestRegistration.hpp"

#define BOOL_VALUE_OF_succeeds true
#define BOOL_VALUE_OF_fails false

#define TYPE_ASSERTION_TEST_CASE(TestCase) \
template <typename T, bool shouldSucceed> \
class TestCase : public AbstractTypeAssertionTest<T, shouldSucceed> { \
}

#define TYPE_ASSERTION_TEST(TestCase, TestName) \
    MAKE_TYPE_ASSERTION_TEST(TestCase, TestName, \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, abstractParent))

#define MAKE_TYPE_ASSERTION_TEST(TestCase, TestName, AbstractParent) \
    MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS(TestCase, AbstractParent); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, AbstractParent, \
            succeeds); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, AbstractParent, \
            fails); \
    START_TYPE_ASSERTION_TEST_BODY(AbstractParent)

#define MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS(TestCase, AbstractParent) \
template <typename gtest_TypeParam_, bool shouldSucceed> \
class AbstractParent : public TestCase<gtest_TypeParam_, shouldSucceed> { \
private: \
    typedef gtest_TypeParam_ TypeParam; \
    typedef TestCase<TypeParam, shouldSucceed> TestFixture; \
\
protected: \
    virtual void TestBody(); \
}

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, SuperClass, \
        TestType) \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_CALLED( \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
            SuperClass, BOOL_VALUE_OF_##TestType)

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_CALLED(ClassName, SuperClass, \
        ShouldSucceed) \
template <typename gtest_TypeParam_> \
class ClassName : public SuperClass<gtest_TypeParam_, ShouldSucceed> { \
protected: \
    using SuperClass<gtest_TypeParam_, ShouldSucceed>::TestBody; \
}

#define START_TYPE_ASSERTION_TEST_BODY(AbstractParent) \
template <typename gtest_TypeParam_, bool shouldSucceed> \
void AbstractParent<gtest_TypeParam_, shouldSucceed>::TestBody()

#define SHOULD_SUCCEED(TestCase, TestName, ...) \
    REGISTER_TYPE_ASSERTION_TEST(TestCase, TestName, succeeds, __VA_ARGS__)

#define SHOULD_FAIL(TestCase, TestName, ...) \
    REGISTER_TYPE_ASSERTION_TEST(TestCase, TestName, fails, __VA_ARGS__)

#define REGISTER_TYPE_ASSERTION_TEST(TestCase, TestName, TestType, ...) \
    bool gtest_##TestCase##_##TestName##_##TestType##_registered_ \
            GTEST_ATTRIBUTE_UNUSED_ = \
        ::testing::internal::TypeAssertionTestRegistration<TestCase, \
                GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
                BOOL_VALUE_OF_##TestType, __VA_ARGS__> \
                    ::Register(#TestCase "." #TestName, #TestType)

#endif
