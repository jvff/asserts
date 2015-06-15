#ifndef ASSERT_THAT_HPP
#define ASSERT_THAT_HPP

#include <string>

#include <boost/format.hpp>

#include "Of.hpp"
#include "TestReporter.hpp"
#include "TypeOf.hpp"

#define TYPE_ASSERTION(methodName, testCondition, messageParameters...) \
    static ASSERTION(methodName, testCondition, TypeOf<T>(), \
            ## messageParameters)

#define ASSERTION(methodName, testCondition, messageParameters...) \
    ASSERTION_WITH_MESSAGE(methodName, testCondition, \
            methodName##FailureMessage, ## messageParameters)

#define ASSERTION_WITH_MESSAGE(methodName, testCondition, failureMessageName, \
        messageParameters...) \
    void methodName() { \
        test(testCondition, failureMessageName, ## messageParameters); \
    } \
\
private: \
    static const std::string failureMessageName; \
\
public:

template<typename T>
class AssertThat {
public:
    TYPE_ASSERTION(hasVirtualDestructor, std::has_virtual_destructor<T>::value)
    TYPE_ASSERTION(isClassOrStruct, std::is_class<T>::value)

    template <class T2>
    static void isSubClass(const Of<T2>&) {
        test(std::is_base_of<T2, T>::value, isSubClassFailureMessage,
                TypeOf<T>(), TypeOf<T2>());
    }

private:
    static const std::string isSubClassFailureMessage;

public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;

    ASSERTION(isNotNull, subject != NULL)
    ASSERTION(isNull, subject == NULL)

private:
    static void test(bool result, const std::string& failureMessage) {
        if (result == true)
            TestReporter::succeed();
        else
            TestReporter::fail(failureMessage);
    }

    template <typename... ParameterTypes>
    static void test(bool result, const std::string& failureMessage,
            ParameterTypes... messageParameters) {
        if (result == true)
            TestReporter::succeed();
        else
            fail(boost::format(failureMessage), messageParameters...);
    }

    static void fail(boost::format failureMessage) {
        TestReporter::fail(failureMessage.str());
    }

    template <typename ParameterType, typename... ParameterTypes>
    static void fail(boost::format failureMessage,
            ParameterType messageParameter,
            ParameterTypes... messageParameters) {
        fail(failureMessage % messageParameter, messageParameters...);
    }
};

#endif
