#ifndef ASSERTS_HPP
#define ASSERTS_HPP

#include "TestReporter.hpp"

template<typename T>
class AssertThat {
public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;

    void isNull() {
        TestReporter::succeed();
    }
};

template<typename T>
AssertThat<T> assertThat(const T& reference) {
    return {reference};
}

#endif
