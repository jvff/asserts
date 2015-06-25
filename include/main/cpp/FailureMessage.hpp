#ifndef FAILURE_MESSAGE_HPP
#define FAILURE_MESSAGE_HPP

template <int messageId>
struct FailureMessage {
    static const std::string message;
};

template <int messageId>
const std::string FailureMessage<messageId>::message = "";

#endif
