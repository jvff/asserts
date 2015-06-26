#ifndef FAILURE_MESSAGE_HPP
#define FAILURE_MESSAGE_HPP

template <int messageId>
struct FailureMessage {
    static const std::string message;
};

template <int messageId>
const std::string FailureMessage<messageId>::message = "";

const int isNullFailureMessageId = 1;

template <>
struct FailureMessage<isNullFailureMessageId> {
    static const std::string message;
};

const std::string FailureMessage<isNullFailureMessageId>::message =
        "Pointer should be NULL";

#endif
