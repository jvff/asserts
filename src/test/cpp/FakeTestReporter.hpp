#ifndef FAKE_TEST_REPORTER_HPP
#define FAKE_TEST_REPORTER_HPP

class FakeTestReporter {
public:
    static bool failed;
    static bool succeeded;

public:
    static void reset() {
        succeeded = false;
        failed = false;
    }

    static void succeed() {
        succeeded = true;
    }

    static void fail() {
        failed = true;
    }
};

#define TEST_REPORTER FakeTestReporter

#endif
