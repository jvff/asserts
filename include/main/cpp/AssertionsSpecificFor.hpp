#ifndef ASSERTIONS_SPECIFIC_FOR_HPP
#define ASSERTIONS_SPECIFIC_FOR_HPP

#include "AssertionMethodMacros.hpp"
#include "CommonAssertions.hpp"

template <typename T>
class AssertionsSpecificFor : public CommonAssertions<T> {
public:
    AssertionsSpecificFor(const T& testSubject)
            : CommonAssertions<T>(testSubject) {
    }
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...)> :
        public CommonAssertions<ReturnType(ClassType::*)(ParameterTypes...)> {
private:
    using SubjectType = ReturnType (ClassType::*)(ParameterTypes...);

protected:
    using CommonAssertions<SubjectType>::noMessageParameters;

public:
    AssertionsSpecificFor(const SubjectType& testSubject)
            : CommonAssertions<SubjectType>(testSubject) {
    }

    ASSERTION(isConstMethod, false, noMessageParameters)
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...) const> :
        public CommonAssertions<
                ReturnType(ClassType::*)(ParameterTypes...) const> {
private:
    using SubjectType = ReturnType (ClassType::*)(ParameterTypes...) const;

protected:
    using CommonAssertions<SubjectType>::noMessageParameters;

public:
    AssertionsSpecificFor(const SubjectType& testSubject)
            : CommonAssertions<SubjectType>(testSubject) {
    }

    ASSERTION(isConstMethod, true, noMessageParameters)
};

#endif
