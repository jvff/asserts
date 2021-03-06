#ifndef CONSTRUCTIBLE_TEST_HPP
#define CONSTRUCTIBLE_TEST_HPP

#include "DummyTypes.hpp"

class ClassWithNoConstructor {
    ClassWithNoConstructor() = delete;
};

class AbstractClassWithDefaultConstructor {
    virtual void abstractMethod() = 0;
};

class ClassWithDefaultConstructor {
};

class ClassWithConstructorWithOneIntParameter {
public:
    ClassWithConstructorWithOneIntParameter(int) {
    }
};

class ClassWithConstructorWithIntAndDummyParameter {
public:
    ClassWithConstructorWithIntAndDummyParameter(int, DummyType) {
    }
};

#endif
