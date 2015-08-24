#ifndef ASSERT_THAT_HPP
#define ASSERT_THAT_HPP

#include <string>

#include <boost/format.hpp>

#include "AssertionMethodMacros.hpp"
#include "AssertionsSpecificFor.hpp"
#include "Formatter.hpp"
#include "TestReporter.hpp"

template<typename T>
class AssertThat : public AssertionsSpecificFor<T> {
public:
    TYPE_ASSERTION(hasVirtualDestructor, std::has_virtual_destructor<T>::value)
    TYPE_ASSERTION(isAbstractClassOrStruct, std::is_abstract<T>::value)
    TYPE_ASSERTION(isClassOrStruct, std::is_class<T>::value)
    TYPE_ASSERTION(isCopyConstructible, std::is_copy_constructible<T>::value)

    TYPE_ASSERTION_WITH_PARAM(isSubClass, std::is_base_of<T2, T>::value)
    TYPE_ASSERTION_WITH_PARAM(isTheSame, std::is_same<T, T2>::value)

    TYPE_ASSERTION_WITH_PARAMS(isConstructible,
            std::is_constructible<T, Params...>::value)

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
    ASSERTION_WITH_PARAM(isNotEqualTo, !(subject == parameter), parameter,
            subject)

    ASSERTION_WITH_PARAM(isAtSameAddressAs, &subject == &parameter, subject,
            parameter)
    ASSERTION_WITH_PARAM(isNotAtSameAddressAs, &subject != &parameter, subject,
            parameter)

private:
    template <typename... ParameterTypes>
    static void test(bool result, const std::string& failureMessage,
            const ParameterTypes&... messageParameters) {
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
            const ParameterType& messageParameter,
            const ParameterTypes&... messageParameters) {
        fail(failureMessage % format(messageParameter), messageParameters...);
    }
};

#endif
