#ifndef ASSERTIONS_SPECIFIC_FOR_HPP
#define ASSERTIONS_SPECIFIC_FOR_HPP

#include "AssertionMethodMacros.hpp"
#include "CommonAssertions.hpp"

template <typename T>
class AssertionsSpecificFor : public CommonAssertions<T> {
public:
    AssertionsSpecificFor() {
    }

    AssertionsSpecificFor(const T&) {
    }
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...)> :
        public CommonAssertions<ReturnType(ClassType::*)(ParameterTypes...)> {
private:
    using SubjectType = ReturnType (ClassType::*)(ParameterTypes...);

public:
    AssertionsSpecificFor() {
    }

    AssertionsSpecificFor(const SubjectType&) {
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

public:
    AssertionsSpecificFor() {
    }

    AssertionsSpecificFor(const SubjectType&) {
    }

    ASSERTION(isConstMethod, true)
    ASSERTION(isMethod, true)
};

#endif
