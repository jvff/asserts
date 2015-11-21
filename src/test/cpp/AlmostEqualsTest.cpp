#include "AlmostEqualsTest.hpp"

VALUE_ASSERTION_TEST_CASE(AlmostEqualsTest);

VALUE_ASSERTION_TEST(AlmostEqualsTest, isAlmostEqualTo) {
    assertThat(std::get<0>(parameter)).isAlmostEqualTo(std::get<1>(parameter));

    checkResult("Expected something almost equal to %s, but %s was found",
            std::get<1>(parameter), std::get<0>(parameter));
}

VALUES_SHOULD_SUCCEED(AlmostEqualsTest, isAlmostEqualTo,
        sameValue(0),
        sameValue(155),
        sameValue(0.f),
        sameValue(0.00005f),
        valuePlusEpsilon(44379.82f),
        valueMinusEpsilon(44379.82f),
        valuePlusEpsilon(0.0000013f),
        valueMinusEpsilon(0.0000013f),
        sameValue(0.0),
        sameValue(0.000000000009),
        valuePlusEpsilon(12.9401e14),
        valueMinusEpsilon(12.9401e14),
        valuePlusEpsilon(12.9401e-14),
        valueMinusEpsilon(12.9401e-14),
        sameValue((long double)0.0),
        sameValue((long double)0.000000000009),
        valuePlusEpsilon((long double)12.9401e14),
        valueMinusEpsilon((long double)12.9401e14),
        valuePlusEpsilon((long double)12.9401e-14),
        valueMinusEpsilon((long double)12.9401e-14));
VALUES_SHOULD_FAIL(AlmostEqualsTest, isAlmostEqualTo,
        std::make_tuple(1, 2),
        std::make_tuple(0, 1),
        std::make_tuple(0, -1),
        std::make_tuple(0.f, 0.1f),
        std::make_tuple(0.f, -0.1f),
        std::make_tuple(0.1f, -0.1f),
        std::make_tuple(-0.1f, 0.1f),
        valuePlusMultipleEpsilons(44379.82f, 2),
        valueMinusMultipleEpsilons(44379.82f, 2),
        valuePlusMultipleEpsilons(0.0000013f, 2),
        valueMinusMultipleEpsilons(0.0000013f, 2),
        std::make_tuple(0.9, 0.91),
        std::make_tuple(1.0, 1.00001),
        std::make_tuple(1.0, -1.00001),
        std::make_tuple(-0.000001, 0.000001),
        valuePlusMultipleEpsilons(12.9401e14, 2),
        valueMinusMultipleEpsilons(12.9401e14, 2),
        valuePlusMultipleEpsilons(12.9401e-14, 2),
        valueMinusMultipleEpsilons(12.9401e-14, 2),
        std::make_tuple((long double)0.9, (long double)0.91),
        std::make_tuple((long double)1.0, (long double)1.00001),
        std::make_tuple((long double)1.0, (long double)-1.00001),
        std::make_tuple((long double)-0.000001, (long double)0.000001),
        valuePlusMultipleEpsilons((long double)12.9401e14, 2),
        valueMinusMultipleEpsilons((long double)12.9401e14, 2),
        valuePlusMultipleEpsilons((long double)12.9401e-14, 2),
        valueMinusMultipleEpsilons((long double)12.9401e-14, 2));
