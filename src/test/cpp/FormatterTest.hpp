#ifndef FORMATTER_TEST_HPP
#define FORMATTER_TEST_HPP

#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "Formatter.hpp"

class FormatterTest : public testing::Test {
protected:
    template <typename T>
    std::string streamStringValueOf(const T& value) {
        std::stringstream stream;

        stream << value;

        return stream.str();
    }

    template <typename T>
    void testFormatter(const Formatter<T>& formatter,
            const std::string& expectedResult) {
        EXPECT_EQ(expectedResult, streamStringValueOf(formatter));
    }

    template <typename T>
    void testFormatter(const Formatter<T>& formatter, const T& value) {
        testFormatter(formatter, streamStringValueOf(value));
    }

    template <typename T>
    void testFormatter(const T& value) {
        testFormatter(Formatter<T>(value), value);
    }

    template <typename T>
    void testFormat(const T& value, const std::string& expectedResult) {
        testFormatter(format(value), expectedResult);
    }

    template <typename T>
    void testFormat(const T& value) {
        testFormat(format(value), streamStringValueOf(value));
    }
};

#endif
