#ifndef FAKE_ASSERTIONS_SPECIFIC_FOR_HPP
#define FAKE_ASSERTIONS_SPECIFIC_FOR_HPP

#include "AssertionsSpecificFor.hpp"

template <typename T>
class FakeAssertionsSpecificFor : public AssertionsSpecificFor<T> {
public:
    FakeAssertionsSpecificFor(const T& testSubject)
            : AssertionsSpecificFor<T>(testSubject) {
    }

    const T& getSubject() {
        return this->subject;
    }
};

#endif
