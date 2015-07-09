#include <type_traits>

#include <gtest/gtest.h>

#include "Formatter.hpp"

#include "DummyTypes.hpp"

TEST(FormatterTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<Formatter<DummyType> >::value));
}
