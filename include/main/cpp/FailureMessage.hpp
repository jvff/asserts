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

MSG(hasVirtualDestructor, "%s should have virtual destructor");
MSG(isAbstractClassOrStruct, "%s should be an abstract class or struct");
MSG(isClassOrStruct, "%s should be a class or a struct");
MSG(isConst, "%s should be read-only (const)");
MSG(isConstReference, "%s should be a reference to a read-only (const) type");
MSG(isConstructible, "%s should be constructible");
MSG(isCopyConstructible, "%s should be copy constructible");
MSG(isNonConstReference, "%s should be a reference to a read-write (non-const) "
        "type");
MSG(isNotConstructible, "%s should not be constructible");
MSG(isNotCopyConstructible, "%s should not be copy constructible");
MSG(isSubClass, "%s should be a sub-class of %s");
MSG(isTheSame, "%s should be the same type as %s");

MSG(isAtSameAddressAs, "Expected %s to be at the same address as %s");
MSG(isConstMethod, "Expected %s to be a const qualified method");
MSG(isAlmostEqualTo, "Expected something almost equal to %s, but %s was found");
MSG(isDifferentThan, "Expected something different than %s, but %s was found");
MSG(isEqualTo, "Expected something equal to %s, but %s was found");
MSG(isGreaterThan, "Expected something greater than %s, but %s was found");
MSG(isLessThan, "Expected something less than %s, but %s was found");
MSG(isMethod, "Expected %s to be a method%s%s");
MSG(isNotAtSameAddressAs, "Expected %s to not be at the same address as %s");
MSG(isNotDifferentThan, "Expected something that's not different than %s, but "
        "%s was found");
MSG(isNotEqualTo, "Expected something not equal to %s, but %s was found");
MSG(isNotGreaterThan, "Expected something not greater than %s, but %s was "
        "found");
MSG(isNotLessThan, "Expected something not less than %s, but %s was found");
MSG(isNotNull, "Pointer should not be NULL");
MSG(isNull, "Pointer should be NULL");

template <int messageId>
using FailureMessage = FailureMessageTemplate<messageId, 0>;

#endif
