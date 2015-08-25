#include <type_traits>

#include "CommonAssertionsTest.hpp"

TEST_F(CommonAssertionsTest, classExists) {
    using DummyCommonAssertions = CommonAssertions<DummyType>;

    EXPECT_TRUE((std::is_class<DummyCommonAssertions>::value));
}
