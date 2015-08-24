#ifndef METHOD_TEST_HPP
#define METHOD_TEST_HPP

#include "gtest/gtest.h"

class DummyClass {
public:
    void constMethod() const {}
    void nonConstMethod() {}
};

#endif
