#ifndef ASSERTIONS_SPECIFIC_FOR_HPP
#define ASSERTIONS_SPECIFIC_FOR_HPP

#include "AssertionMethodMacros.hpp"
#include "CommonAssertions.hpp"

template <typename T>
class AssertionsSpecificFor : public CommonAssertions {
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...)> :
        public CommonAssertions {
public:
    ASSERTION(isConstMethod, false)
};

template <typename ClassType, typename ReturnType, typename... ParameterTypes>
class AssertionsSpecificFor<ReturnType(ClassType::*)(ParameterTypes...) const> :
        public CommonAssertions {
public:
    ASSERTION(isConstMethod, true)
};

#endif
