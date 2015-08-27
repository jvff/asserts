#ifndef METHOD_TEST_HPP
#define METHOD_TEST_HPP

#include "gtest/gtest.h"

#include "WithSignature.hpp"

class DummyClass {
public:
    void constMethod() const {}
    void nonConstMethod() {}
};

template <typename MethodType, typename ExpectedSignature>
struct MethodAndSignaturePair {
    using Signature = ExpectedSignature;

    const MethodType& method;

    MethodAndSignaturePair(const MethodType& methodReference)
            : method(methodReference) {
    }
};

#endif
