#ifndef TYPE_ASSERTION_TEST_REGISTRATION_HPP
#define TYPE_ASSERTION_TEST_REGISTRATION_HPP

#include <string>
#include <type_traits>

#include "gtest/gtest.h"

#include "VoidAssertionTest.hpp"

namespace testing {
namespace internal {

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed,
        typename... Tail>
class TypeAssertionTestRegistration {
private:
    static bool Register(const std::string&, const std::string&);
};

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed,
        typename T, typename... Tail>
class TypeAssertionTestRegistration<FixtureClassTemplate, TestClassTemplate,
        shouldSucceed, T, Tail...> {
public:
    static bool Register(const std::string& testCaseName,
            const std::string& testName) {
        typedef FixtureClassTemplate<T, shouldSucceed> FixtureClass;
        typedef TestClassTemplate<T> TestClass;

        std::string currentTestCaseName = testCaseName + "." + getTypeName();

        MakeAndRegisterTestInfo(currentTestCaseName.c_str(), testName.c_str(),
                NULL, NULL, GetTypeId<FixtureClass>(), TestClass::SetUpTestCase,
                TestClass::TearDownTestCase, new TestFactoryImpl<TestClass>);

        return TypeAssertionTestRegistration<FixtureClassTemplate,
                TestClassTemplate, shouldSucceed, Tail...>
                    ::Register(testCaseName, testName);
    }

    static std::string getTypeName() {
        std::string typeName = GetTypeName<T>();

        if (std::is_const<T>::value)
            typeName = "const " + typeName;
        if (std::is_reference<T>::value) {
            using referencedType = typename std::remove_reference<T>::type;

            typeName += "&";

            if (std::is_const<referencedType>::value)
                typeName = "const " + typeName;
        }

        return typeName;
    }
};

template <template <typename, bool> class FixtureClassTemplate,
        template <typename> class TestClassTemplate, bool shouldSucceed>
class TypeAssertionTestRegistration<FixtureClassTemplate, TestClassTemplate,
        shouldSucceed> {
public:
    static bool Register(const std::string&, const std::string&) {
        return true;
    }
};

template <template <typename, bool> class FixtureClassTemplate,
        bool shouldSucceed, typename T, typename... Tail>
class TypeAssertionTestRegistration<FixtureClassTemplate, VoidAssertionTest,
        shouldSucceed, T, Tail...> {
public:
    static bool Register(const std::string&, const std::string&) {
        return false;
    }
};

}
}

#endif
