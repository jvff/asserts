#ifndef ASSERT_THAT_HPP
#define ASSERT_THAT_HPP

#include "AssertionMethodMacros.hpp"
#include "AssertionsSpecificFor.hpp"

template<typename T>
class AssertThat : public AssertionsSpecificFor<T> {
protected:
    using AssertionsSpecificFor<T>::subject;
    using CommonAssertions<T>::noMessageParameters;

public:
    TYPE_ASSERTION(hasVirtualDestructor, std::has_virtual_destructor<T>::value)
    TYPE_ASSERTION(isAbstractClassOrStruct, std::is_abstract<T>::value)
    TYPE_ASSERTION(isClassOrStruct, std::is_class<T>::value)
    TYPE_ASSERTION(isConst, std::is_const<T>::value)
    TYPE_ASSERTION(isCopyConstructible, std::is_copy_constructible<T>::value)
    TYPE_ASSERTION(isNotCopyConstructible,
            !std::is_copy_constructible<T>::value)

    TYPE_ASSERTION_WITH_PARAM(isSubClass, std::is_base_of<T2, T>::value)
    TYPE_ASSERTION_WITH_PARAM(isTheSame, std::is_same<T, T2>::value)

    TYPE_ASSERTION_WITH_PARAMS(isConstructible,
            std::is_constructible<T, Params...>::value)
    TYPE_ASSERTION_WITH_PARAMS(isNotConstructible,
            !std::is_constructible<T, Params...>::value)

public:
    AssertThat(const T& reference) : AssertionsSpecificFor<T>(reference) {
    }

    AssertThat(const AssertThat<T>& objectToCopy)
            : AssertionsSpecificFor<T>(objectToCopy) {
    }

    AssertThat(AssertThat<T>&&) = delete;

    ASSERTION(isNotNull, subject != NULL, noMessageParameters)
    ASSERTION(isNull, subject == NULL, noMessageParameters)

    ASSERTION(isMethod, std::is_member_function_pointer<T>::value, subject, "",
            "")

    ASSERTION_WITH_PARAM(isEqualTo, subject == parameter, parameter, subject)
    ASSERTION_WITH_PARAM(isNotEqualTo, !(subject == parameter), parameter,
            subject)
    ASSERTION_WITH_PARAM(isDifferentThan, subject != parameter, parameter,
            subject)
    ASSERTION_WITH_PARAM(isNotDifferentThan, !(subject != parameter), parameter,
            subject)

    ASSERTION_WITH_PARAM(isLessThan, subject < parameter, parameter, subject)
    ASSERTION_WITH_PARAM(isNotLessThan, !(subject < parameter), parameter,
            subject)

    ASSERTION_WITH_PARAM(isAtSameAddressAs, &subject == &parameter, subject,
            parameter)
    ASSERTION_WITH_PARAM(isNotAtSameAddressAs, &subject != &parameter, subject,
            parameter)

    using AssertionsSpecificFor<T>::isMethod;
};

#endif
