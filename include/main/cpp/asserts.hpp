#ifndef ASSERTS_HPP
#define ASSERTS_HPP

#include "AssertThat.hpp"

template<typename T>
AssertThat<T> assertThat(const T& reference) {
    return {reference};
}

#endif
