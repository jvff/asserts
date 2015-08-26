#include <type_traits>

#include "gtest/gtest.h"

#include "WithSignature.hpp"

#include "DummyTypes.hpp"

TEST(WithSignatureTest, classTemplateExists) {
    EXPECT_TRUE((std::is_class<WithSignature<DummyType> >::value));
}
