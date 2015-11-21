#ifndef ALMOST_EQUALS_TEST_HPP
#define ALMOST_EQUALS_TEST_HPP

#include "ValueAssertionMacros.hpp"

template <typename T>
static std::tuple<T, T> sameValue(const T& value) {
    return std::make_tuple(value, value);
}

template <typename T>
static T epsilon(const T& value) {
    T scale = std::abs(value);

    return scale * std::numeric_limits<T>::epsilon();
}

template <typename T>
static std::tuple<T, T> valuePlusEpsilon(const T& value) {
    auto valueWithEpsilon = value + epsilon(value);

    return std::make_tuple(value, valueWithEpsilon);
}

template <typename T>
static std::tuple<T, T> valueMinusEpsilon(const T& value) {
    auto valueWithEpsilon = value - epsilon(value);

    return std::make_tuple(value, valueWithEpsilon);
}

template <typename T>
static std::tuple<T, T> valuePlusMultipleEpsilons(const T& value,
        unsigned int numberOfEpsilons) {
    auto valueWithEpsilon = value + numberOfEpsilons * epsilon(value);

    return std::make_tuple(value, valueWithEpsilon);
}

template <typename T>
static std::tuple<T, T> valueMinusMultipleEpsilons(const T& value,
        unsigned int numberOfEpsilons) {
    auto valueWithEpsilon = value - numberOfEpsilons * epsilon(value);

    return std::make_tuple(value, valueWithEpsilon);
}

#endif
