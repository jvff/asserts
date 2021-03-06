#include "ValueAssertionMacros.hpp"

VALUE_ASSERTION_TEST_CASE(OrderTest);

VALUE_ASSERTION_TEST(OrderTest, isLessThan) {
    assertThat(std::get<0>(parameter)).isLessThan(std::get<1>(parameter));

    checkResult("Expected something less than %s, but %s was found",
            std::get<1>(parameter), std::get<0>(parameter));
}

VALUE_ASSERTION_TEST(OrderTest, isNotLessThan) {
    assertThat(std::get<0>(parameter)).isNotLessThan(std::get<1>(parameter));

    checkResult("Expected something not less than %s, but %s was found",
            std::get<1>(parameter), std::get<0>(parameter));
}

VALUE_ASSERTION_TESTS_ARE_OPPOSITE(OrderTest, isLessThan, isNotLessThan);

VALUES_SHOULD_SUCCEED(OrderTest, isLessThan,
        std::make_tuple(0, 1),
        std::make_tuple(-1, 1),
        std::make_tuple(-4839, -3199),
        std::make_tuple(-4839, 3199),
        std::make_tuple(4839, 13199),
        std::make_tuple(-0.125f, 2000.f),
        std::make_tuple(0.125f, 100.f),
        std::make_tuple(-0.000008, 1000000.0),
        std::make_tuple(800.0, 200000.0),
        std::make_tuple(std::make_pair(1, 100), std::make_pair(100, 1)));
VALUES_SHOULD_FAIL(OrderTest, isLessThan,
        std::make_tuple(1, 0),
        std::make_tuple(1, 1),
        std::make_tuple(1, -1),
        std::make_tuple(-1, -1),
        std::make_tuple(-3199, -4839),
        std::make_tuple(-3199, -3199),
        std::make_tuple(3199, -4839),
        std::make_tuple(13199, 4839),
        std::make_tuple(13199, 13199),
        std::make_tuple(2000.f, -0.125f),
        std::make_tuple(2000.f, 2000.f),
        std::make_tuple(-0.125f, -0.125f),
        std::make_tuple(100.f, 0.125f),
        std::make_tuple(1000000.0, -0.000008),
        std::make_tuple(1000000.0, 1000000.0),
        std::make_tuple(-0.000008, -0.000008),
        std::make_tuple(200000.0, 800.0),
        std::make_tuple(std::make_pair(100, 1), std::make_pair(1, 100)),
        std::make_tuple(std::make_pair(100, 100), std::make_pair(100, 100)));

VALUE_ASSERTION_TEST(OrderTest, isGreaterThan) {
    assertThat(std::get<1>(parameter)).isGreaterThan(std::get<0>(parameter));

    checkResult("Expected something greater than %s, but %s was found",
            std::get<0>(parameter), std::get<1>(parameter));
}

VALUE_ASSERTION_TEST(OrderTest, isNotGreaterThan) {
    assertThat(std::get<1>(parameter)).isNotGreaterThan(std::get<0>(parameter));

    checkResult("Expected something not greater than %s, but %s was found",
            std::get<0>(parameter), std::get<1>(parameter));
}

VALUE_ASSERTION_TESTS_ARE_OPPOSITE(OrderTest, isGreaterThan, isNotGreaterThan);

VALUES_SHOULD_SUCCEED(OrderTest, isGreaterThan,
        std::make_tuple(0, 1),
        std::make_tuple(-1, 1),
        std::make_tuple(-4839, -3199),
        std::make_tuple(-4839, 3199),
        std::make_tuple(4839, 13199),
        std::make_tuple(-0.125f, 2000.f),
        std::make_tuple(0.125f, 100.f),
        std::make_tuple(-0.000008, 1000000.0),
        std::make_tuple(800.0, 200000.0),
        std::make_tuple(std::make_pair(1, 100), std::make_pair(100, 1)));
VALUES_SHOULD_FAIL(OrderTest, isGreaterThan,
        std::make_tuple(1, 0),
        std::make_tuple(1, 1),
        std::make_tuple(1, -1),
        std::make_tuple(-1, -1),
        std::make_tuple(-3199, -4839),
        std::make_tuple(-3199, -3199),
        std::make_tuple(3199, -4839),
        std::make_tuple(13199, 4839),
        std::make_tuple(13199, 13199),
        std::make_tuple(2000.f, -0.125f),
        std::make_tuple(2000.f, 2000.f),
        std::make_tuple(-0.125f, -0.125f),
        std::make_tuple(100.f, 0.125f),
        std::make_tuple(1000000.0, -0.000008),
        std::make_tuple(1000000.0, 1000000.0),
        std::make_tuple(-0.000008, -0.000008),
        std::make_tuple(200000.0, 800.0),
        std::make_tuple(std::make_pair(100, 1), std::make_pair(1, 100)),
        std::make_tuple(std::make_pair(100, 100), std::make_pair(100, 100)));
