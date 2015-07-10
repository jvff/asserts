#include <type_traits>

#include "DummyTypes.hpp"
#include "FormatterTest.hpp"
#include "PrintableClass.hpp"
#include "UnprintableClass.hpp"

TEST_F(FormatterTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<Formatter<DummyType> >::value));
}

TEST_F(FormatterTest, isConstructibleWithParameter) {
    typedef Formatter<DummyType> formatter;
    typedef DummyType parameter;

    EXPECT_TRUE((std::is_constructible<formatter, parameter>::value));
}

TEST_F(FormatterTest, formatterIsPrintable) {
    testFormatter(2);
}

TEST_F(FormatterTest, formatFunctionReturnsFormatter) {
    typedef Formatter<DummyType> expected;
    typedef decltype(format(DummyType())) actual;

    EXPECT_TRUE((std::is_same<expected, actual>::value));
}

TEST_F(FormatterTest, formatValueOne) {
    testFormat(1);
}

TEST_F(FormatterTest, formatTrueValue) {
    testFormat(true, "true");
}

TEST_F(FormatterTest, formatFalseValue) {
    testFormat(false, "false");
}

TEST_F(FormatterTest, formatPrintableClass) {
    PrintableClass printableObject;

    testFormat(printableObject);
}

TEST_F(FormatterTest,formatUnprintableClass) {
    UnprintableClass unprintableObject;
    std::stringstream expected;

    expected << "?(UnprintableClass@" << (void*)&unprintableObject << ")";

    testFormat(unprintableObject, expected.str());
}
