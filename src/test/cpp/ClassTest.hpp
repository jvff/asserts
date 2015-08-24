#ifndef CLASS_TEST_HPP
#define CLASS_TEST_HPP

#include "DummyTypes.hpp"

class DummyClass {
};

union DummyUnion {
};

class DummyAbstractClass {
public:
    virtual void abstractMethod() = 0;
};

struct DummyAbstractStruct {
    virtual void abstractMethod() = 0;
};

class DummyAbstractSubClass : DummyAbstractClass {
};

struct DummyAbstractSubStruct : DummyAbstractStruct {
};

class BaseClass {
};

class DerivedClass : BaseClass {
};

#endif
