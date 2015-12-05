#include "DummyTypes.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(ConstTest);

TYPE_ASSERTION_TEST(ConstTest, isConst) {
    AssertThat<TypeParam>::isConst();

    this->checkResult("%s should be read-only (const)");
}

SHOULD_SUCCEED(ConstTest, isConst,
        const char,
        const unsigned short,
        const int,
        void* const,
        const DummyType);
SHOULD_FAIL(ConstTest, isConst,
        char,
        unsigned short,
        int,
        void*,
        const void*,
        float&,
        const float&,
        DummyType,
        DummyType&,
        const DummyType&);
