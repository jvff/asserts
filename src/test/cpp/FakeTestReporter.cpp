#include "FakeTestReporter.hpp"

static const std::string emptyMessage = "";

bool FakeTestReporter::failed = false;
bool FakeTestReporter::succeeded = false;
std::reference_wrapper<const std::string> FakeTestReporter::failureMessage
        = emptyMessage;
