#include "gtest/gtest.h"

#include "FailureMessage.hpp"

TEST(FailureMessageTest, structTemplateExists) {
    EXPECT_TRUE((std::is_class<FailureMessage<0> >::value));
}

TEST(FailureMessageTest, invalidFailureMessageIsEmpty) {
    EXPECT_EQ("", FailureMessage<-1>::message);
}

TEST(FailureMessageTest, isNullFailureMessageExists) {
    EXPECT_EQ("Pointer should be NULL",
            FailureMessage<isNullFailureMessageId>::message);
}
