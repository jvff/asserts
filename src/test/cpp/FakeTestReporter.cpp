#include "FakeTestReporter.hpp"

bool FakeTestReporter::failed = false;
bool FakeTestReporter::succeeded = false;
std::unique_ptr<const std::string> FakeTestReporter::failureMessage{nullptr};

void FakeTestReporter::reset() {
    succeeded = false;
    failed = false;
    failureMessage.reset();
}

void FakeTestReporter::succeed() {
    succeeded = true;
}

void FakeTestReporter::fail(const std::string& message) {
    failed = true;
    failureMessage.reset(new std::string(message));
}
