#ifndef FAKE_TEST_REPORTER_HPP
#define FAKE_TEST_REPORTER_HPP

#include <memory>
#include <string>

class FakeTestReporter {
public:
    static bool failed;
    static bool succeeded;
    static std::unique_ptr<const std::string> failureMessage;

public:
    static void reset();
    static void succeed();
    static void fail(const std::string& message);
};

#define TEST_REPORTER FakeTestReporter

#endif
