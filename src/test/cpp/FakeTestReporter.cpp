#include "FakeTestReporter.hpp"

static const std::string emptyMessage = "";

bool FakeTestReporter::failed = false;
bool FakeTestReporter::succeeded = false;
std::reference_wrapper<const std::string> FakeTestReporter::failureMessage
        = emptyMessage;

void FakeTestReporter::reset() {
    succeeded = false;
    failed = false;
    failureMessage = emptyMessage;
}

void FakeTestReporter::succeed() {
    succeeded = true;
}

void FakeTestReporter::fail(const std::string& message) {
    failed = true;
    failureMessage = message;
}
