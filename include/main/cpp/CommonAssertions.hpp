#ifndef COMMON_ASSERTIONS_HPP
#define COMMON_ASSERTIONS_HPP

#include <string>

#include "TestReporter.hpp"

class CommonAssertions {
protected:
    static void test(bool result, const std::string& failureMessage) {
	if (result == true)
	    TestReporter::succeed();
	else
	    TestReporter::fail(failureMessage);
    }
};

#endif
