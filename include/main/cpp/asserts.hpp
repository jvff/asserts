#ifndef ASSERTS_HPP
#define ASSERTS_HPP

template<typename T>
class AssertThat {
public:
    explicit AssertThat(const T& reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;
};

template<typename T>
AssertThat<T> assertThat(const T& reference) {
    T subject;

    return {subject};
}

#endif
