#ifndef ASSERTIONS_SPECIFIC_FOR_HPP
#define ASSERTIONS_SPECIFIC_FOR_HPP

#include "AssertionMethodMacros.hpp"
#include "CommonAssertions.hpp"

template <typename T>
class AssertionsSpecificFor : public CommonAssertions<T> {
protected:
    const T& subject;

public:
    AssertionsSpecificFor(const T& testSubject)
            : CommonAssertions<T>(testSubject), subject(testSubject) {
    }
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...)> :
        public CommonAssertions<ReturnType(ClassType::*)(ParameterTypes...)> {
private:
    using SubjectType = ReturnType (ClassType::*)(ParameterTypes...);

protected:
    const SubjectType& subject;

public:
    AssertionsSpecificFor(const SubjectType& testSubject)
            : CommonAssertions<SubjectType>(testSubject), subject(testSubject) {
    }

    ASSERTION(isConstMethod, false)
    ASSERTION(isMethod, true)
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...) const> :
        public CommonAssertions<
                ReturnType(ClassType::*)(ParameterTypes...) const> {
private:
    using SubjectType = ReturnType (ClassType::*)(ParameterTypes...) const;

protected:
    const SubjectType& subject;

public:
    AssertionsSpecificFor(const SubjectType& testSubject)
            : CommonAssertions<SubjectType>(testSubject), subject(testSubject) {
    }

    ASSERTION(isConstMethod, true)
    ASSERTION(isMethod, true)
};

#endif
