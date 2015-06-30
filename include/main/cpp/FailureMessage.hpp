#ifndef FAILURE_MESSAGE_HPP
#define FAILURE_MESSAGE_HPP

#define DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE() \
    template <int messageId, int unusedParameter> \
    DECLARE_FAILURE_MESSAGE_STRUCT()

#define DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE_SPECIALIZATION(MessageId) \
    template <int unusedParameter> \
    DECLARE_FAILURE_MESSAGE_STRUCT(<MessageId, unusedParameter>)

#define DECLARE_FAILURE_MESSAGE_STRUCT(...) \
    struct FailureMessageTemplate __VA_ARGS__ { \
        static const std::string message; \
    }

#define DEFINE_MESSAGE_ID(MessageId) \
    const int MessageId = __COUNTER__

#define DEFINE_MESSAGE_TEMPLATE(Message) \
    template <int messageId, int unusedParameter> \
    const std::string FailureMessageTemplate<messageId, unusedParameter> \
	    ::message = Message

#define DEFINE_MESSAGE(MessageId, Message) \
    template <int unusedParameter> \
    const std::string FailureMessageTemplate<MessageId, unusedParameter> \
	    ::message = Message

#define MAKE_MESSAGE(MessageId, Message) \
    DEFINE_MESSAGE_ID(MessageId); \
    DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE_SPECIALIZATION(MessageId); \
    DEFINE_MESSAGE(MessageId, Message)

#define MSG(MessageName, Message) \
    MAKE_MESSAGE(MessageName##FailureMessageId, Message)

DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE();
DEFINE_MESSAGE_TEMPLATE("");

MSG(isNull, "Pointer should be NULL");

template <int messageId>
using FailureMessage = FailureMessageTemplate<messageId, 0>;

#endif
