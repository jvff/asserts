#ifndef ASSERTS_HPP
#define ASSERTS_HPP

#include <string>

#include "TestReporter.hpp"

template<typename T>
class AssertThat {
private:
    static const std::string classShouldHaveVirtualDestructorMessage;
    static const std::string pointerShouldBeNullMessage;
    static const std::string typeShouldBeClassOrStructMessage;

public:
    static void isClassOrStruct() {
        test(std::is_class<T>::value, typeShouldBeClassOrStructMessage);
    }

    static void hasVirtualDestructor() {
        test(std::has_virtual_destructor<T>::value,
                classShouldHaveVirtualDestructorMessage);
    }

private:
    static void test(bool result, const std::string& failureMessage) {
        if (result == true)
            TestReporter::succeed();
        else
            TestReporter::fail(failureMessage);
    }

public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;

    void isNull() {
        test(subject == NULL, pointerShouldBeNullMessage);
    }
};

#include "failure_messages.hpp"

template<typename T>
AssertThat<T> assertThat(const T& reference) {
    return {reference};
}

#endif
