#include "gtest/gtest.h"

#include "FailureMessage.hpp"

TEST(FailureMessageTest, structTemplateExists) {
    EXPECT_TRUE((std::is_class<FailureMessage<0> >::value));
}
