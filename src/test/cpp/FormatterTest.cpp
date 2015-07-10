#include <type_traits>

#include <gtest/gtest.h>

#include "Formatter.hpp"

#include "DummyTypes.hpp"

TEST(FormatterTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<Formatter<DummyType> >::value));
}

TEST(FormatterTest, isConstructibleWithParameter) {
    typedef Formatter<DummyType> formatter;
    typedef DummyType parameter;

    EXPECT_TRUE((std::is_constructible<formatter, parameter>::value));
}

TEST(FormatterTest, formatterIsPrintable) {
    int value = 2;

    Formatter<int> formatter(value);
    std::stringstream expected, actual;

    expected << value;
    actual << formatter;

    EXPECT_EQ(expected.str(), actual.str());
}

TEST(FormatterTest, formatFunctionReturnsFormatter) {
    typedef Formatter<DummyType> expected;
    typedef decltype(format(DummyType())) actual;

    EXPECT_TRUE((std::is_same<expected, actual>::value));
}

TEST(FormatterTest, formatValueOne) {
    std::stringstream stream;

    stream << format(1);

    EXPECT_EQ("1", stream.str());
}

TEST(FormatterTest, formatTrueValue) {
    std::stringstream stream;

    stream << format(true);

    EXPECT_EQ("true", stream.str());
}
