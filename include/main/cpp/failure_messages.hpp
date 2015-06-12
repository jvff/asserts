#ifndef FAILURE_MESSAGES_HPP
#define FAILURE_MESSAGES_HPP

#define MSG(name, message) \
template <typename T> \
const std::string AssertThat<T>::name ## FailureMessage = message

MSG(hasVirtualDestructor, "Class should have virtual destructor");
MSG(isClassOrStruct, "Type should be a class or a struct");

MSG(isNotNull, "Pointer should not be NULL");
MSG(isNull, "Pointer should be NULL");

#endif
