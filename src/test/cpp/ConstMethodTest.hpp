#ifndef CONST_METHOD_TEST_HPP
#define CONST_METHOD_TEST_HPP

#include "gtest/gtest.h"

class DummyClass {
public:
    void constMethod() const {}
    void nonConstMethod() {}
};

#endif
