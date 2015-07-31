#ifndef COPY_CONSTRUCTIBLE_TEST_HPP
#define COPY_CONSTRUCTIBLE_TEST_HPP

class ClassWithDefaultConstructors {
};

class ClassWithDefaultCopyConstructor {
public:
    ClassWithDefaultCopyConstructor(const ClassWithDefaultCopyConstructor&)
            = default;
};

class ClassWithCustomCopyConstructor {
public:
    ClassWithCustomCopyConstructor(const ClassWithDefaultCopyConstructor&) {
    }
};

class ClassWithNoConstructors {
    ClassWithNoConstructors() = delete;
};

class ClassWithDeletedCopyConstructor {
public:
    ClassWithDeletedCopyConstructor(const ClassWithDeletedCopyConstructor&)
            = delete;
};

class ClassWithCustomConstructorButNoCopyConstructor {
public:
    ClassWithCustomConstructorButNoCopyConstructor() {
    }
};

#endif
