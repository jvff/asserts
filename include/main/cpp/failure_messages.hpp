#ifndef FAILURE_MESSAGES_HPP
#define FAILURE_MESSAGES_HPP

#define MSG(name, message) \
template <typename T> \
const std::string AssertThat<T>::name ## FailureMessage = message

MSG(hasVirtualDestructor, "%s should have virtual destructor");
MSG(isClassOrStruct, "%s should be a class or a struct");
MSG(isSubClass, "%s should be a sub-class of %s");
MSG(isTheSame, "%s should be the same type as %s");

MSG(isEqualTo, "Expected something equal to %s, but %s was found");
MSG(isNotNull, "Pointer should not be NULL");
MSG(isNull, "Pointer should be NULL");

#endif
