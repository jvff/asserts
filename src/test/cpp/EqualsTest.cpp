#include <iostream>
#include "ValueAssertionMacros.hpp"

VALUE_ASSERTION_TEST_CASE(EqualsTest);

VALUE_ASSERTION_TEST(EqualsTest, isEqualTo) {
    assertThat(std::get<0>(parameter)).isEqualTo(std::get<1>(parameter));

    checkResult("Expected something equal to %s, but %s was found",
            std::get<1>(parameter), std::get<0>(parameter));
}

VALUES_SHOULD_SUCCEED(EqualsTest, isEqualTo, std::make_tuple(3, 3));
VALUES_SHOULD_FAIL(EqualsTest, isEqualTo, std::make_tuple(3, 4));
