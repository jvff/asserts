#ifndef FAILURE_MESSAGE_HPP
#define FAILURE_MESSAGE_HPP

#define DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE() \
    template <int messageId> \
    DECLARE_FAILURE_MESSAGE_STRUCT()

#define DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE_SPECIALIZATION(MessageId) \
    template <> \
    DECLARE_FAILURE_MESSAGE_STRUCT(<MessageId>)

#define DECLARE_FAILURE_MESSAGE_STRUCT(Specialization) \
    struct FailureMessage Specialization { \
        static const std::string message; \
    }

#define DEFINE_MESSAGE_ID(MessageId) \
    const int MessageId = __COUNTER__

#define DEFINE_MESSAGE_TEMPLATE(Message) \
    template <int messageId> \
    const std::string FailureMessage<messageId>::message = Message

#define DEFINE_MESSAGE(MessageId, Message) \
    const std::string FailureMessage<MessageId>::message = Message

#define MAKE_MESSAGE(MessageId, Message) \
    DEFINE_MESSAGE_ID(MessageId); \
    DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE_SPECIALIZATION(MessageId); \
    DEFINE_MESSAGE(MessageId, Message)

#define MSG(MessageName, Message) \
    MAKE_MESSAGE(MessageName##FailureMessageId, Message)

DECLARE_FAILURE_MESSAGE_STRUCT_TEMPLATE();
DEFINE_MESSAGE_TEMPLATE("");

MSG(isNull, "Pointer should be NULL");

#endif
