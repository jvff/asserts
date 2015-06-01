#ifndef FAILURE_MESSAGES_HPP
#define FAILURE_MESSAGES_HPP

#define MSG(name, message) \
template <typename T> \
const std::string AssertThat<T>::name = message

MSG(pointerShouldBeNullMessage, "Pointer should be NULL");
MSG(typeShouldBeClassOrStructMessage, "Type should be a class or a struct");

#endif
