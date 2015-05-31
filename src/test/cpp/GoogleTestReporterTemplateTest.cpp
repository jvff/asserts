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
    EXPECT_TRUE((std::is_class<FakeGoogleTestReporter>::value));
}

TEST(GoogleTestReporterTemplateTest, failMethod) {
    std::string errorMessage = "Test error message";
    std::stringstream stream;

    failStream = &stream;

    FakeGoogleTestReporter::fail(errorMessage);

    EXPECT_EQ(errorMessage, stream.str());
}

TEST(GoogleTestReporterTemplateTest, succeedMethod) {
    successFlag = false;

    FakeGoogleTestReporter::succeed();

    EXPECT_TRUE(successFlag);
}

TEST(GoogleTestReporterTest, testReporterTypeAliasWasDefined) {
    EXPECT_TRUE((std::is_same<FakeGoogleTestReporter, TestReporter>::value));
}
