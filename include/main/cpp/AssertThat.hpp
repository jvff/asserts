#ifndef ASSERT_THAT_HPP
#define ASSERT_THAT_HPP

#include <string>

#include <boost/format.hpp>

#include "AssertionMethodMacros.hpp"
#include "AssertionsSpecificFor.hpp"
#include "FailureMessage.hpp"
#include "Of.hpp"
#include "TestReporter.hpp"
#include "TypeOf.hpp"

template<typename T>
class AssertThat : public AssertionsSpecificFor<T> {
public:
    TYPE_ASSERTION(hasVirtualDestructor, std::has_virtual_destructor<T>::value)
    TYPE_ASSERTION(isClassOrStruct, std::is_class<T>::value)

    TYPE_ASSERTION_WITH_PARAM(isSubClass, std::is_base_of<T2, T>::value)
    TYPE_ASSERTION_WITH_PARAM(isTheSame, std::is_same<T, T2>::value)

public:
    const T& subject;

public:
    AssertThat(const T& reference) : subject(reference) {
    }

    AssertThat(AssertThat<T>&) = delete;
    AssertThat(AssertThat<T>&&) = delete;

    ASSERTION(isNotNull, subject != NULL)
    ASSERTION(isNull, subject == NULL)

    ASSERTION_WITH_PARAM(isEqualTo, subject == parameter, parameter, subject)

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
