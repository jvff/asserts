#ifndef TEST_REPORTER_HPP
#define TEST_REPORTER_HPP

#if defined TEST_REPORTER
    typedef TEST_REPORTER TestReporter;
#elif defined GTEST_INCLUDE_GTEST_GTEST_H_
    #include "GoogleTestReporter.hpp"
#else
    #error "No supported test library detected"
#endif

#endif
