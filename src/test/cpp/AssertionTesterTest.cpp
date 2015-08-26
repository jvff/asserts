#include "AssertionTesterTest.hpp"

TEST_F(AssertionTesterTest, classExists) {
    EXPECT_TRUE((std::is_class<AssertionTester>::value));
}

TEST_F(AssertionTesterTest, isNotConstructible) {
    EXPECT_FALSE((std::is_constructible<AssertionTester>::value));
}

TEST_F(AssertionTesterTest, testMethodSucceeds) {
    AssertionTester::test(true, "");

    shouldSucceed();
}

TEST_F(AssertionTesterTest, testMethodFails) {
    AssertionTester::test(false, "Fake test failure message");

    shouldFail("Fake test failure message");
}

TEST_F(AssertionTesterTest, testMethodFailsWithParameter) {
    int parameter = 86;
    const std::string message = "Fake test failure message with parameter (%s)";

    AssertionTester::test(false, message, parameter);

    shouldFail("Fake test failure message with parameter (86)");
}

TEST_F(AssertionTesterTest, testMethodFailsWithParameters) {
    int firstParameter = 86;
    char secondParameter = 'a';
    const std::string message =
            "Fake test failure message with parameter (%s, %s)";

    AssertionTester::test(false, message, firstParameter, secondParameter);

    shouldFail("Fake test failure message with parameter (86, a)");
}

TEST_F(AssertionTesterTest, testMethodFailsWithInvalidParameter) {
    const std::string message = "Fake test failure message without parameters";
    AssertionTester::InvalidParameter invalidParameter;

    AssertionTester::test(false, message, invalidParameter);

    shouldFail(message);
}
