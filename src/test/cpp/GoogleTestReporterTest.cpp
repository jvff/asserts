#include "gtest/gtest.h"

#include "GoogleTestReporterTemplate.hpp"

#ifdef DECLARE_GOOGLE_TEST_REPORTER_CLASS
#undef DECLARE_GOOGLE_TEST_REPORTER_CLASS
#define DECLARE_GOOGLE_TEST_REPORTER_CLASS(className) \
    std::string googleTestReporterClassName = #className
#endif

#include "GoogleTestReporter.hpp"

TEST(GoogleTestReporterTest, classWasCreatedFromTemplate) {
    EXPECT_EQ("GoogleTestReporter", googleTestReporterClassName);
}
