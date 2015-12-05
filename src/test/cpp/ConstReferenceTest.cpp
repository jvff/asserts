#include "DummyTypes.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(ConstReferenceTest);

TYPE_ASSERTION_TEST(ConstReferenceTest, isConstReference) {
    AssertThat<TypeParam>::isConstReference();

    this->checkResult("%s should be a reference to a read-only (const) type");
}

SHOULD_SUCCEED(ConstReferenceTest, isConstReference,
        const char&,
        const unsigned short&,
        const int&,
        void* const&,
        const DummyType&);
SHOULD_FAIL(ConstReferenceTest, isConstReference,
        char,
        const char,
        char&,
        unsigned short,
        const unsigned short,
        unsigned short&,
        int,
        const int,
        int&,
        void*,
        void const*,
        void*&,
        const void*,
        const void*&,
        float,
        const float,
        float&,
        DummyType,
        const DummyType,
        DummyType&);
