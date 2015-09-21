#include "ValueAssertionMacros.hpp"

VALUE_ASSERTION_TEST_CASE(DifferentThanTest);

VALUE_ASSERTION_TEST(DifferentThanTest, isDifferentThan) {
    assertThat(std::get<0>(parameter)).isDifferentThan(std::get<1>(parameter));

    checkResult("Expected something different than %s, but %s was found",
            std::get<1>(parameter), std::get<0>(parameter));
}

VALUES_SHOULD_SUCCEED(DifferentThanTest, isDifferentThan,
        std::make_tuple(true, false),
        std::make_tuple(false, true),
        std::make_tuple(3, 4),
        std::make_tuple(192, -192),
        std::make_tuple(-192, 192),
        std::make_tuple(-0.125, 0.125),
        std::make_tuple(0.125, -0.125),
        std::make_tuple(0.125, 0.25),
        std::make_tuple(0.25, 0.125),
        std::make_tuple(0.125, 0.1251),
        std::make_tuple(0.1251, 0.125),
        std::make_tuple("bla", "iha"));
VALUES_SHOULD_FAIL(DifferentThanTest, isDifferentThan,
        std::make_tuple(true, true),
        std::make_tuple(false, false),
        std::make_tuple(3, 3),
        std::make_tuple(-192, -192),
        std::make_tuple(0.125, 0.125),
        std::make_tuple("bla", "bla"),
        std::make_tuple(std::string("STRING"), "STRING"));
