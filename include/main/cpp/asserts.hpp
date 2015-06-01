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
        if (std::is_class<T>::value == true)
            TestReporter::succeed();
        else
            TestReporter::fail(typeShouldBeClassOrStructMessage);
    }

    static void hasVirtualDestructor() {
        if (std::has_virtual_destructor<T>::value == true)
            TestReporter::succeed();
        else
            TestReporter::fail(classShouldHaveVirtualDestructorMessage);
    }

public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;

    void isNull() {
        if (subject == NULL)
            TestReporter::succeed();
        else
            TestReporter::fail(pointerShouldBeNullMessage);
    }
};

#include "failure_messages.hpp"

template<typename T>
AssertThat<T> assertThat(const T& reference) {
    return {reference};
}

#endif
