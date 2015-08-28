#ifndef TYPE_ASSERTION_MACROS_HPP
#define TYPE_ASSERTION_MACROS_HPP

#include "gtest/gtest.h"

#include "AbstractTypeAssertionTest.hpp"
#include "OppositeAssertionTestTo.hpp"
#include "TypeAssertionTestRegistration.hpp"

#define BOOL_VALUE_OF_succeeds true
#define BOOL_VALUE_OF_fails false

#define TYPENAMES_1 typename gtest_TypeParam_
#define TYPENAMES_2 typename gtest_TypeParam1_, typename gtest_TypeParam2_
#define TYPENAMES_N typename... TypeParams
#define TYPENAMES_1N typename gtest_TypeParam1_, TYPENAMES_N

#define PACK_1 gtest_TypeParam_
#define PACK_2 Pack<gtest_TypeParam1_, gtest_TypeParam2_>
#define PACK_1N Pack<gtest_TypeParam1_, TypeParams...>

#define TYPEDEFS_1 typedef gtest_TypeParam_ TypeParam
#define TYPEDEFS_2 typedef PACK_2 TypeParam; TYPEDEFS_2_
#define TYPEDEFS_1N typedef PACK_1N TypeParam; TYPEDEFS_1_

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
class AbstractParent : public TestCase<PACK_1, shouldSucceed> { \
MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS_BODY(TestCase, 1); \
}

#define MAKE_TYPE_ASSERTION_TEST_PARENT_CLASS_T(TestCase, AbstractParent, \
        NumParams) \
template <typename, bool> \
class AbstractParent; \
\
template <TYPENAMES_##NumParams, bool shouldSucceed> \
class AbstractParent<PACK_##NumParams, shouldSucceed> : \
        public TestCase<PACK_##NumParams, shouldSucceed> { \
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
class ClassName : public SuperClass<PACK_1, ShouldSucceed> { \
protected: \
    using SuperClass<PACK_1, ShouldSucceed>::TestBody; \
}

#define MAKE_TYPE_ASSERTION_TEST_CHILD_CLASS_CALLED_T(ClassName, SuperClass, \
        ShouldSucceed, NumParams) \
template <typename> \
class ClassName; \
\
template <TYPENAMES_##NumParams> \
class ClassName<PACK_##NumParams> : \
        public SuperClass<PACK_##NumParams, ShouldSucceed> { \
protected: \
    using SuperClass<PACK_##NumParams, ShouldSucceed>::TestBody; \
}

#define START_TYPE_ASSERTION_TEST_BODY(AbstractParent, NumParams) \
template <TYPENAMES_##NumParams, bool shouldSucceed> \
void AbstractParent<PACK_##NumParams, shouldSucceed>::TestBody()

#define TYPE_ASSERTION_TESTS_ARE_OPPOSITE(TestCase, NormalTestName, \
        OppositeTestName) \
    MAKE_OPPOSITE_TYPE_ASSERTION_TEST(TestCase, OppositeTestName, \
        GTEST_TEST_CLASS_NAME_(TestCase##_##NormalTestName, abstractParent), \
        GTEST_TEST_CLASS_NAME_(TestCase##_##OppositeTestName, succeeds), \
        GTEST_TEST_CLASS_NAME_(TestCase##_##OppositeTestName, fails))

#define MAKE_OPPOSITE_TYPE_ASSERTION_TEST(TestCase, OppositeTestName, \
        AbstractParent, SucceedsClass, FailsClass) \
    SPECIALIZE_OPPOSITE_TYPE_ASSERTION_TEST(TestCase, AbstractParent, \
            SucceedsClass, FailsClass); \
    DECLARE_OPPOSITE_TYPE_ASSERTION_TEST_NAME(TestCase, OppositeTestName, \
            AbstractParent)

#define SPECIALIZE_OPPOSITE_TYPE_ASSERTION_TEST(TestCase, AbstractParent, \
        SucceedsClass, FailsClass) \
template <> \
struct OppositeAssertionTestTo<TestCase, AbstractParent> { \
    template <typename parameterType> \
    using TestClass_succeeds = SucceedsClass<parameterType>; \
\
    template <typename parameterType> \
    using TestClass_fails = FailsClass<parameterType>; \
\
    static const char* TestCaseName; \
}

#define DECLARE_OPPOSITE_TYPE_ASSERTION_TEST_NAME(TestCase, OppositeTestName, \
        AbstractParent) \
const char* OppositeAssertionTestTo<TestCase, AbstractParent> \
        ::TestCaseName = #TestCase "." #OppositeTestName

#define SHOULD_SUCCEED(TestCase, TestName, ...) \
    REGISTER_TYPE_ASSERTION_TESTS(TestCase, TestName, succeeds, fails, \
            __VA_ARGS__)

#define SHOULD_FAIL(TestCase, TestName, ...) \
    REGISTER_TYPE_ASSERTION_TESTS(TestCase, TestName, fails, succeeds, \
            __VA_ARGS__)

#define REGISTER_TYPE_ASSERTION_TESTS(TestCase, TestName, TestType, \
        OppositeTestType, ...) \
    REGISTER_MAIN_TYPE_ASSERTION_TEST(TestCase, TestName, TestType, \
            __VA_ARGS__); \
    REGISTER_OPPOSITE_TYPE_ASSERTION_TEST(TestCase, TestName, \
            OppositeTestType, \
            OppositeAssertionTest_##TestCase##_##TestName, __VA_ARGS__)

#define REGISTER_MAIN_TYPE_ASSERTION_TEST(TestCase, TestName, TestType, ...) \
    REGISTER_TYPE_ASSERTION_TEST(TestCase, #TestCase "." #TestName, TestName, \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, TestType), TestType, \
            __VA_ARGS__)

#define REGISTER_OPPOSITE_TYPE_ASSERTION_TEST(TestCase, TestName, TestType, \
        OppositeTestName, ...) \
    DEFINE_OPPOSITE_TYPE_ASSERTION_TEST_NAME(TestCase, TestName, \
            OppositeTestName); \
    REGISTER_TYPE_ASSERTION_TEST(TestCase, OppositeTestName::TestCaseName, \
            TestName##_opposite, OppositeTestName::TestClass_##TestType, \
            TestType, __VA_ARGS__)

#define DEFINE_OPPOSITE_TYPE_ASSERTION_TEST_NAME(TestCase, TestName, \
        OppositeTestName) \
    using OppositeTestName = OppositeAssertionTestTo<TestCase, \
            GTEST_TEST_CLASS_NAME_(TestCase##_##TestName, abstractParent)>

#define REGISTER_TYPE_ASSERTION_TEST(TestCase, TestCaseName, TestName, \
        TestClass, TestType, ...) \
    bool gtest_##TestCase##_##TestName##_##TestType##_registered_ \
            GTEST_ATTRIBUTE_UNUSED_ = \
        ::testing::internal::TypeAssertionTestRegistration<TestCase, \
                TestClass, BOOL_VALUE_OF_##TestType, __VA_ARGS__> \
                    ::Register(TestCaseName, #TestType)

#endif
