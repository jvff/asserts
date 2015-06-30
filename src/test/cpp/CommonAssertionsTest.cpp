#include <type_traits>

#include "CommonAssertionsTest.hpp"

TEST_F(CommonAssertionsTest, classExists) {
    EXPECT_TRUE((std::is_class<CommonAssertions>::value));
}
