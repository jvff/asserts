#ifndef CUSTOM_PARAMETERIZED_TEST_MACROS_HPP
#define CUSTOM_PARAMETERIZED_TEST_MACROS_HPP

#include "gtest/gtest.h"

#include "CustomParameterizedTestRegistration.hpp"

#define TEST_PARAMETERS(TestCase, ...) \
    static auto TestCase##_TestParameters = std::make_tuple(__VA_ARGS__); \
    static auto TestCase##_TestParameterNames = std::string(#__VA_ARGS__)

#define TEST_CP(TestCase, TestName) \
   MAKE_TEST_CP_NAMED(TestCase, TestName, \
           GTEST_TEST_CLASS_NAME_(TestCase, TestName))

#define MAKE_TEST_CP_NAMED(TestCase, TestName, ClassName) \
    MAKE_TEST_CP_CLASS(TestCase, ClassName); \
    REGISTER_TEST_CP(TestCase, TestName, ClassName); \
    START_TEST_CP_BODY(ClassName)

#define MAKE_TEST_CP_CLASS(TestCase, ClassName) \
template <typename parameterType> \
class ClassName : public TestCase<parameterType> { \
protected: \
    typedef parameterType ParamType; \
\
private: \
    const ParamType& parameter; \
\
public: \
    ClassName(const ParamType& testParameter) : parameter(testParameter) { \
    } \
\
    virtual void TestBody(); \
}

#define START_TEST_CP_BODY(ClassName) \
template <typename parameterType> \
void ClassName<parameterType>::TestBody()

#define REGISTER_TEST_CP(TestCase, TestName, TestClass) \
    bool gtest_##TestCase##_##TestName##_registered_ GTEST_ATTRIBUTE_UNUSED_ = \
        ::testing::internal::CustomParameterizedTestRegistration<TestCase, \
                TestClass>::Register(#TestCase, #TestName, \
                        TestCase##_TestParameterNames, \
                        TestCase##_TestParameters)

#endif
