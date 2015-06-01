#ifndef ASSERTS_HPP
#define ASSERTS_HPP

#include <string>

#include "TestReporter.hpp"

template<typename T>
class AssertThat {
private:
    static const std::string pointerShouldBeNullMessage;
    static const std::string typeShouldBeClassOrStructMessage;

public:
    static void isClassOrStruct() {
        if (std::is_class<T>::value == true)
            TestReporter::succeed();
        else
            TestReporter::fail(typeShouldBeClassOrStructMessage);
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

template <typename T>
const std::string AssertThat<T>::pointerShouldBeNullMessage = "Pointer should be NULL";
template <typename T>
const std::string AssertThat<T>::typeShouldBeClassOrStructMessage =
        "Type should be a class or a struct";

template<typename T>
AssertThat<T> assertThat(const T& reference) {
    return {reference};
}

#endif
