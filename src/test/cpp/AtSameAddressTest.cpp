#include "DummyTypes.hpp"
#include "ValueAssertionMacros.hpp"

VALUE_ASSERTION_TEST_CASE(AtSameAddressTest);

VALUE_ASSERTION_TEST(AtSameAddressTest, isAtSameAddressAs) {
    auto& firstParameter = std::get<0>(parameter);
    auto& secondParameter = std::get<1>(parameter);

    assertThat(firstParameter).isAtSameAddressAs(secondParameter);

    checkResult("Expected %s to be at the same address as %s", firstParameter,
            secondParameter);
}

static DummyType firstVariable;
static auto& firstRefToFirstVariable = firstVariable;
static auto& secondRefToFirstVariable = firstVariable;

VALUES_SHOULD_SUCCEED(AtSameAddressTest, isAtSameAddressAs,
        std::tie(firstRefToFirstVariable, firstRefToFirstVariable),
        std::tie(secondRefToFirstVariable, secondRefToFirstVariable),
        std::tie(firstRefToFirstVariable, secondRefToFirstVariable),
        std::tie(secondRefToFirstVariable, firstRefToFirstVariable));
