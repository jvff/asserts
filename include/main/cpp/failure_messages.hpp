#ifndef FAILURE_MESSAGES_HPP
#define FAILURE_MESSAGES_HPP

#define MSG(name, message) \
template <typename T> \
const std::string AssertThat<T>::name ## Message = message

MSG(classShouldHaveVirtualDestructor, "Class should have virtual destructor");
MSG(pointerShouldBeNull, "Pointer should be NULL");
MSG(pointerShouldntBeNull, "Pointer should not be NULL");
MSG(typeShouldBeClassOrStruct, "Type should be a class or a struct");

#endif
