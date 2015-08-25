#ifndef FAKE_COMMON_ASSERTIONS_HPP
#define FAKE_COMMON_ASSERTIONS_HPP

#include "FakeTestReporter.hpp"

#include "CommonAssertions.hpp"

template <typename T>
class FakeCommonAssertions : public CommonAssertions<T> {
};

#endif
