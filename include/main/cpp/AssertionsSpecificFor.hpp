#ifndef ASSERTIONS_SPECIFIC_FOR_HPP
#define ASSERTIONS_SPECIFIC_FOR_HPP

#include "AssertionMethodMacros.hpp"
#include "CommonAssertions.hpp"

template <typename T, typename Enable = void>
class AssertionsSpecificFor : public CommonAssertions<T> {
public:
    AssertionsSpecificFor(const T& testSubject)
            : CommonAssertions<T>(testSubject) {
    }
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...), void>
        : public CommonAssertions<ReturnType(ClassType::*)(ParameterTypes...)> {
private:
    using SubjectType = ReturnType (ClassType::*)(ParameterTypes...);
    using Signature = ReturnType(ParameterTypes...);

    using SuperClass = CommonAssertions<SubjectType>;

protected:
    using SuperClass::subject;

public:
    AssertionsSpecificFor(const SubjectType& testSubject)
            : CommonAssertions<SubjectType>(testSubject) {
    }

    ASSERTION_WITH_TYPE_PARAM(isMethod,
            (std::is_same<Signature, typename TypeParam::Signature>::value),
            subject, " with signature ",
            TypeOf<typename TypeParam::Signature>())

    using SuperClass::isMethod;
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...) const,
        void> : public CommonAssertions<
                ReturnType(ClassType::*)(ParameterTypes...) const> {
private:
    using SubjectType = ReturnType (ClassType::*)(ParameterTypes...) const;
    using Signature = ReturnType(ParameterTypes...);

    using SuperClass = CommonAssertions<SubjectType>;

protected:
    using SuperClass::subject;

public:
    AssertionsSpecificFor(const SubjectType& testSubject)
            : CommonAssertions<SubjectType>(testSubject) {
    }

    ASSERTION(isConstMethod, true, subject)

    ASSERTION_WITH_TYPE_PARAM(isMethod,
            (std::is_same<Signature, typename TypeParam::Signature>::value),
            subject, " with signature ",
            TypeOf<typename TypeParam::Signature>())

    using SuperClass::isMethod;
};

template <typename T>
class AssertionsSpecificFor<T,
        typename std::enable_if<std::is_arithmetic<T>::value>::type>
        : public CommonAssertions<T> {
private:
    using SubjectType = T;

    static constexpr SubjectType epsilon = std::numeric_limits<T>::epsilon();
    static constexpr SubjectType minimumValue = std::numeric_limits<T>::min();

protected:
    using CommonAssertions<SubjectType>::subject;

public:
    AssertionsSpecificFor(const SubjectType& testSubject)
            : CommonAssertions<SubjectType>(testSubject) {
    }

    ASSERTION_WITH_PARAM(isAlmostEqualTo, isSubjectAlmostEqualTo(parameter),
            parameter, subject)

private:
    bool isSubjectAlmostEqualTo(const SubjectType& parameter) {
        auto difference = std::abs(subject - parameter);

        if (difference < minimumValue)
            return true;
        else
            return difference <= epsilonFor(subject, parameter);
    }

    SubjectType epsilonFor(const SubjectType& subject,
            const SubjectType& parameter) {
        auto positiveSubject = std::abs(subject);
        auto positiveParameter = std::abs(parameter);
        auto scale = std::max(positiveSubject, positiveParameter);

        return scale * epsilon;
    }
};

#endif
