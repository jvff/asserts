#include <sstream>
#include <string>
#include <type_traits>

#include "gtest/gtest.h"

static std::stringstream* failStream;
static bool successFlag;

#ifdef FAIL
#undef FAIL
#endif

#define FAIL() *failStream << ""

#ifdef SUCCEED
#undef SUCCEED
#endif

#define SUCCEED() successFlag = true

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

TEST(GoogleTestReporterTemplateTest, succeedMethod) {
    FakeGoogleTestReporter* reporter;

    successFlag = false;

    reporter = new FakeGoogleTestReporter();

    reporter->succeed();

    EXPECT_TRUE(successFlag);

    delete reporter;
}

TEST(GoogleTestReporterTest, testReporterTypeAliasWasDefined) {
    EXPECT_TRUE((std::is_same<FakeGoogleTestReporter, TestReporter>::value));
}