#ifndef ASSERT_THAT_HPP
#define ASSERT_THAT_HPP

#include <string>

#include "TestReporter.hpp"

#define ASSERTION(methodName, testCondition, failureMessageName) \
    void methodName() { \
        test(testCondition, failureMessageName##Message); \
    } \
\
private: \
    static const std::string failureMessageName##Message; \
\
public:

template<typename T>
class AssertThat {
public:
    static ASSERTION(hasVirtualDestructor,
            std::has_virtual_destructor<T>::value,
            classShouldHaveVirtualDestructor)
    static ASSERTION(isClassOrStruct, std::is_class<T>::value,
            typeShouldBeClassOrStruct)

public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;

    ASSERTION(isNull, subject == NULL, pointerShouldBeNull)
    ASSERTION(isNotNull, subject != NULL, pointerShouldntBeNull)

private:
    static void test(bool result, const std::string& failureMessage) {
        if (result == true)
            TestReporter::succeed();
        else
            TestReporter::fail(failureMessage);
    }
};

#endif
