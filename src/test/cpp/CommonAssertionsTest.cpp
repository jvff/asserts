#include <type_traits>

#include "CommonAssertionsTest.hpp"

TEST_F(CommonAssertionsTest, classExists) {
    EXPECT_TRUE((std::is_class<CommonAssertions>::value));
}

TEST_F(CommonAssertionsTest, testMethodSucceeds) {
    FakeCommonAssertions::test(true, "");

    shouldSucceed();
}

TEST_F(CommonAssertionsTest, testMethodFails) {
    FakeCommonAssertions::test(false, "Fake test failure message");

    shouldFail("Fake test failure message");
}

TEST_F(CommonAssertionsTest, testMethodFailsWithParameter) {
    int parameter = 86;
    const std::string message = "Fake test failure message with parameter (%s)";

    FakeCommonAssertions::test(false, message, parameter);

    shouldFail("Fake test failure message with parameter (86)");
}

TEST_F(CommonAssertionsTest, testMethodFailsWithParameters) {
    int firstParameter = 86;
    char secondParameter = 'a';
    const std::string message =
            "Fake test failure message with parameter (%s, %s)";

    FakeCommonAssertions::test(false, message, firstParameter, secondParameter);

    shouldFail("Fake test failure message with parameter (86, a)");
}
