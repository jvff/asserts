#include "gtest/gtest.h"

#include "FailureReporterTemplate.hpp"

DECLARE_FAILURE_REPORTER_CLASS(FakeFailureReporter);

TEST(FailureReporterTemplateTest, templateMakesAClass) {
    FakeFailureReporter *reporter;

    reporter = new FakeFailureReporter();

    EXPECT_TRUE(reporter != NULL);

    delete reporter;
}
