#ifndef FAKE_COMMON_ASSERTIONS_HPP
#define FAKE_COMMON_ASSERTIONS_HPP

#include "FakeTestReporter.hpp"

#include "CommonAssertions.hpp"

template <typename T>
class FakeCommonAssertions : public CommonAssertions<T> {
public:
    FakeCommonAssertions(const T& subject) : CommonAssertions<T>(subject) {
    }

    const T& getSubject() {
        return this->subject;
    }
};

#endif
