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

#define TYPE_ASSERTION_TEST(TestCase) \
    TYPE_ASSERTION_TEST_CASE(TestCase); \
    TYPE_ASSERTION_TEST_F(TestCase)

#define TYPE_ASSERTION_TEST_F(TestCase) \
    MAKE_TYPE_ASSERTION_TEST(TestCase, \
            GTEST_TEST_CLASS_NAME_(TestCase, abstractParent))

#define MAKE_TYPE_ASSERTION_TEST(TestCase, AbstractParent) \
    MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS(TestCase, AbstractParent); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, AbstractParent, succeeds); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, AbstractParent, fails); \
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

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, SuperClass, TestName) \
template <typename gtest_TypeParam_> \
class GTEST_TEST_CLASS_NAME_(TestCase, TestName) : \
        public SuperClass<gtest_TypeParam_, BOOL_VALUE_OF_##TestName> { \
protected: \
    using SuperClass<gtest_TypeParam_, BOOL_VALUE_OF_##TestName>::TestBody; \
}

#define START_TYPE_ASSERTION_TEST_BODY(AbstractParent) \
template <typename gtest_TypeParam_, bool shouldSucceed> \
void AbstractParent<gtest_TypeParam_, shouldSucceed>::TestBody()

#define SHOULD_SUCCEED(TestCase, ...) \
    REGISTER_TYPE_ASSERTION_TEST(TestCase, succeeds, __VA_ARGS__)

#define SHOULD_FAIL(TestCase, ...) \
    REGISTER_TYPE_ASSERTION_TEST(TestCase, fails, __VA_ARGS__)

#define REGISTER_TYPE_ASSERTION_TEST(TestCase, TestName, ...) \
    bool gtest_##TestCase##_##TestName##_registered_ GTEST_ATTRIBUTE_UNUSED_ = \
        ::testing::internal::TypeAssertionTestRegistration \
                <TestCase, GTEST_TEST_CLASS_NAME_(TestCase, TestName), \
                BOOL_VALUE_OF_##TestName, __VA_ARGS__> \
                    ::Register(#TestCase, #TestName)

#endif
