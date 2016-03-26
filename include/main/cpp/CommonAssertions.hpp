#ifndef COMMON_ASSERTIONS_HPP
#define COMMON_ASSERTIONS_HPP

#include "AssertionMethodMacros.hpp"

template <typename T>
class CommonAssertions {
protected:
    const T& subject;

    AssertionTester::InvalidParameter noMessageParameters;

public:
    CommonAssertions(const T& testSubject) : subject(testSubject) {
    }

    ASSERTION(isConstMethod, false, subject)

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
    ASSERTION_WITH_PARAM(isGreaterThan, subject > parameter, parameter, subject)
    ASSERTION_WITH_PARAM(isNotGreaterThan, !(subject > parameter), parameter,
            subject)

    ASSERTION_WITH_PARAM(isAtSameAddressAs, &subject == &parameter, subject,
            parameter)
    ASSERTION_WITH_PARAM(isNotAtSameAddressAs, &subject != &parameter, subject,
            parameter)

    ASSERTION_WITH_TYPE_PARAM(isMethod, false, subject, " with signature ",
            TypeOf<typename TypeParam::Signature>())
};

#endif
