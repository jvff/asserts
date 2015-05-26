#ifndef ASSERTS_HPP
#define ASSERTS_HPP

template<typename T>
class AssertThat {
public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;
};

template<typename T>
AssertThat<T> assertThat(const T& reference) {
    return {reference};
}

#endif
