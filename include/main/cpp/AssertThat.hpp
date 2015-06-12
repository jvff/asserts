#ifndef ASSERT_THAT_HPP
#define ASSERT_THAT_HPP

#include <string>

#include "TestReporter.hpp"

#define ASSERTION(methodName, testCondition) \
    ASSERTION_WITH_MESSAGE(methodName, testCondition, \
            methodName##FailureMessage)

#define ASSERTION_WITH_MESSAGE(methodName, testCondition, failureMessageName) \
    void methodName() { \
        test(testCondition, failureMessageName); \
    } \
\
private: \
    static const std::string failureMessageName; \
\
public:

template<typename T>
class AssertThat {
public:
    static ASSERTION(hasVirtualDestructor,
            std::has_virtual_destructor<T>::value)
    static ASSERTION(isClassOrStruct, std::is_class<T>::value)

public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;

    ASSERTION(isNotNull, subject != NULL)
    ASSERTION(isNull, subject == NULL)

private:
    static void test(bool result, const std::string& failureMessage) {
        if (result == true)
            TestReporter::succeed();
        else
            TestReporter::fail(failureMessage);
    }
};

#endif
