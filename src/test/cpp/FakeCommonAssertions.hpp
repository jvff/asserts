#ifndef FAKE_COMMON_ASSERTIONS_HPP
#define FAKE_COMMON_ASSERTIONS_HPP

#include "FakeTestReporter.hpp"

#include "CommonAssertions.hpp"

class FakeCommonAssertions : public CommonAssertions {
public:
    using CommonAssertions::test;
};

#endif
