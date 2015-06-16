#ifndef TYPE_ASSERTION_MACROS_HPP
#define TYPE_ASSERTION_MACROS_HPP

#include "gtest/gtest.h"

#include "AbstractTypeAssertionTest.hpp"
#include "TypeAssertionTestRegistration.hpp"

#define BOOL_VALUE_OF_succeeds true
#define BOOL_VALUE_OF_fails false

#define TYPENAMES_1 typename gtest_TypeParam_
#define TYPENAMES_2 typename gtest_TypeParam1_, typename gtest_TypeParam2_

#define TUPLE_1 gtest_TypeParam_
#define TUPLE_2 std::tuple<gtest_TypeParam1_, gtest_TypeParam2_>

#define TYPEDEFS_1 typedef gtest_TypeParam_ TypeParam
#define TYPEDEFS_2 typedef TUPLE_2 TypeParam; TYPEDEFS_2_

#define TYPEDEFS_1_ typedef gtest_TypeParam1_ TypeParam1
#define TYPEDEFS_2_ typedef gtest_TypeParam2_ TypeParam2; TYPEDEFS_1_

#define TYPE_ASSERTION_TEST_CASE(TestCase) \
template <typename T, bool shouldSucceed> \
class TestCase : public AbstractTypeAssertionTest<T, shouldSucceed> { \
}

#define TYPE_ASSERTION_TEST(TestCase, TestName) \
    MAKE_TYPE_ASSERTION_TEST(TestCase, TestName, \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, abstractParent))

#define TYPE_ASSERTION_TEST_T(TestCase, TestName, NumParams) \
    MAKE_TYPE_ASSERTION_TEST_T(TestCase, TestName, NumParams, \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, abstractParent))

#define MAKE_TYPE_ASSERTION_TEST(TestCase, TestName, AbstractParent) \
    MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS(TestCase, AbstractParent); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, AbstractParent, \
            succeeds); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, AbstractParent, \
            fails); \
    START_TYPE_ASSERTION_TEST_BODY(AbstractParent, 1)

#define MAKE_TYPE_ASSERTION_TEST_T(TestCase, TestName, NumParams, \
        AbstractParent) \
    MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS_T(TestCase, AbstractParent, \
            NumParams); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_T(TestCase, TestName, AbstractParent, \
            succeeds, NumParams); \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_T(TestCase, TestName, AbstractParent, \
            fails, NumParams); \
    START_TYPE_ASSERTION_TEST_BODY(AbstractParent, NumParams)

#define MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS(TestCase, AbstractParent) \
template <TYPENAMES_1, bool shouldSucceed> \
class AbstractParent : public TestCase<TUPLE_1, shouldSucceed> { \
MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS_BODY(TestCase, 1); \
}

#define MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS_T(TestCase, AbstractParent, \
        NumParams) \
template <typename, bool> \
class AbstractParent; \
\
template <TYPENAMES_##NumParams, bool shouldSucceed> \
class AbstractParent<TUPLE_##NumParams, shouldSucceed> : \
        public TestCase<TUPLE_##NumParams, shouldSucceed> { \
MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS_BODY(TestCase, NumParams); \
}

#define MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS_BODY(TestCase, NumParams) \
private: \
    TYPEDEFS_##NumParams; \
    typedef TestCase<TypeParam, shouldSucceed> TestFixture; \
\
protected: \
    virtual void TestBody()

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS(TestCase, TestName, SuperClass, \
        TestType) \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_CALLED( \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
            SuperClass, BOOL_VALUE_OF_##TestType)

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_T(TestCase, TestName, SuperClass, \
        TestType, NumParams) \
    MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_CALLED_T( \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), \
            SuperClass, BOOL_VALUE_OF_##TestType, NumParams)

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_CALLED(ClassName, SuperClass, \
        ShouldSucceed) \
template <TYPENAMES_1> \
class ClassName : public SuperClass<TUPLE_1, ShouldSucceed> { \
protected: \
    using SuperClass<TUPLE_1, ShouldSucceed>::TestBody; \
}

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_CALLED_T(ClassName, SuperClass, \
        ShouldSucceed, NumParams) \
template <typename> \
class ClassName; \
\
template <TYPENAMES_##NumParams> \
class ClassName<TUPLE_##NumParams> : \
        public SuperClass<TUPLE_##NumParams, ShouldSucceed> { \
protected: \
    using SuperClass<TUPLE_##NumParams, ShouldSucceed>::TestBody; \
}

#define START_TYPE_ASSERTION_TEST_BODY(AbstractParent, NumParams) \
template <TYPENAMES_##NumParams, bool shouldSucceed> \
void AbstractParent<TUPLE_##NumParams, shouldSucceed>::TestBody()

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
