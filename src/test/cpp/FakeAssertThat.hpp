#ifndef FAKE_ASSERT_THAT_HPP
#define FAKE_ASSERT_THAT_HPP

#include "AssertThat.hpp"

template <typename T>
class FakeAssertThat : public AssertThat<T> {
public:
    FakeAssertThat(const T& testSubject) : AssertThat<T>(testSubject) {
    }

    FakeAssertThat(const AssertThat<T>& assertion) : AssertThat<T>(assertion) {
    }

    const T& getSubject() {
        return this->subject;
    }
};

#endif
