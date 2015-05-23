#include "gtest/gtest.h"

#include "FailureReporterTemplate.hpp"

#ifdef DECLARE_FAILURE_REPORTER_CLASS
#undef DECLARE_FAILURE_REPORTER_CLASS
#define DECLARE_FAILURE_REPORTER_CLASS(className) \
    std::string failureReporterClassName = #className
#endif

#include "FailureReporter.hpp"

TEST(FailureReporterTest, classWasCreatedFromTemplate) {
    EXPECT_EQ("FailureReporter", failureReporterClassName);
}
