#include <sstream>
#include <string>

#include "gtest/gtest.h"

static std::stringstream* failStream;

#ifdef FAIL
#undef FAIL
#endif

#define FAIL() *failStream << ""

#include "GoogleTestReporterTemplate.hpp"

DECLARE_GOOGLE_TEST_REPORTER_CLASS(FakeGoogleTestReporter);

TEST(GoogleTestReporterTemplateTest, templateMakesAClass) {
    FakeGoogleTestReporter *reporter;

    reporter = new FakeGoogleTestReporter();

    EXPECT_TRUE(reporter != NULL);

    delete reporter;
}

TEST(GoogleTestReporterTemplateTest, failMethod) {
    std::string errorMessage = "Test error message";
    FakeGoogleTestReporter *reporter;
    std::stringstream stream;

    failStream = &stream;

    reporter = new FakeGoogleTestReporter();

    reporter->fail(errorMessage);

    EXPECT_EQ(errorMessage, stream.str());

    delete reporter;
}
