#include "DummyTypes.hpp"
#include "TypeAssertionMacros.hpp"

TYPE_ASSERTION_TEST_CASE(NonConstReferenceTest);

TYPE_ASSERTION_TEST(NonConstReferenceTest, isNonConstReference) {
    AssertThat<TypeParam>::isNonConstReference();

    this->checkResult("%s should be a reference to a read-write "
            "(non-const) type");
}

SHOULD_SUCCEED(NonConstReferenceTest, isNonConstReference,
        char&,
        unsigned short&,
        int&,
        void*&,
        const void*&,
        float&,
        DummyType&);
SHOULD_FAIL(NonConstReferenceTest, isNonConstReference,
        char,
        const char,
        const char&,
        unsigned short,
        const unsigned short,
        const unsigned short&,
        int,
        const int,
        const int&,
        void*,
        void const*,
        void* const&,
        const void*,
        float,
        const float,
        const float&,
        DummyType,
        const DummyType,
        const DummyType&);
