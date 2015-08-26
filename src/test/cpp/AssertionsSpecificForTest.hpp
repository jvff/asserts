#ifndef ASSERTIONS_SPECIFIC_FOR_TEST_HPP
#define ASSERTIONS_SPECIFIC_FOR_TEST_HPP

#include <type_traits>

#include "gtest/gtest.h"

#include "AssertionsSpecificFor.hpp"

#include "CustomParameterizedTestMacros.hpp"
#include "DummyTypes.hpp"
#include "FakeAssertionsSpecificFor.hpp"

template <typename T>
class AssertionsSpecificForTest : public testing::Test {
};

class DummyClass {
public:
    void method() {}
    void constMethod() const {}
};

#endif
