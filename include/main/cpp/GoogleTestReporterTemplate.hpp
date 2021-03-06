#ifndef GOOGLE_TEST_REPORTER_TEMPLATE_HPP
#define GOOGLE_TEST_REPORTER_TEMPLATE_HPP

#include <string>

#include "gtest/gtest.h"

#define DECLARE_GOOGLE_TEST_REPORTER_CLASS(className) \
class className { \
public: \
    static void fail(std::string errorMessage) { \
        FAIL() << errorMessage; \
    } \
\
    static void succeed() { \
    } \
}; \
\
typedef className TestReporter

#endif
