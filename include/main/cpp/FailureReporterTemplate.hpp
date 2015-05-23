#ifndef FAILURE_REPORTER_TEMPLATE_HPP
#define FAILURE_REPORTER_TEMPLATE_HPP

#include <string>

#include "gtest/gtest.h"

#define DECLARE_FAILURE_REPORTER_CLASS(className) \
class className { \
public: \
    virtual void fail(std::string errorMessage) { \
        FAIL() << errorMessage; \
    } \
}

#endif
