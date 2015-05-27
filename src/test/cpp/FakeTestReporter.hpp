#ifndef FAKE_TEST_REPORTER_HPP
#define FAKE_TEST_REPORTER_HPP

#include <functional>
#include <string>

class FakeTestReporter {
public:
    static bool failed;
    static bool succeeded;
    static std::reference_wrapper<const std::string> failureMessage;

public:
    static void reset() {
        succeeded = false;
        failed = false;
    }

    static void succeed() {
        succeeded = true;
    }

    static void fail(const std::string& message) {
        failed = true;
        failureMessage = message;
    }
};

#define TEST_REPORTER FakeTestReporter

#endif
