#include "ValueAssertionMacros.hpp"

VALUE_ASSERTION_TEST_CASE(EqualsTest);

VALUE_ASSERTION_TEST(EqualsTest, isEqualTo) {
    assertThat(std::get<0>(parameter)).isEqualTo(std::get<1>(parameter));

    checkResult("Expected something equal to %s, but %s was found",
            std::get<1>(parameter), std::get<0>(parameter));
}

VALUES_SHOULD_SUCCEED(EqualsTest, isEqualTo,
        std::make_tuple(true, true),
        std::make_tuple(false, false),
        std::make_tuple(3, 3),
        std::make_tuple(-192, -192),
        std::make_tuple(0.125, 0.125),
        std::make_tuple("bla", "bla"),
        std::make_tuple(std::string("STRING"), "STRING"));
VALUES_SHOULD_FAIL(EqualsTest, isEqualTo,
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
