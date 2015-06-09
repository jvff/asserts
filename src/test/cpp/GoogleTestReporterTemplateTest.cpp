#include <sstream>
#include <string>
#include <type_traits>

#include "gtest/gtest.h"

static std::stringstream* failStream;

#ifdef FAIL
#undef FAIL
#endif

#define FAIL() *failStream << ""

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
    std::stringstream stream;

    failStream = &stream;

    FakeGoogleTestReporter::succeed();

    EXPECT_EQ("", stream.str());
}

TEST(GoogleTestReporterTest, testReporterTypeAliasWasDefined) {
    EXPECT_TRUE((std::is_same<FakeGoogleTestReporter, TestReporter>::value));
}
