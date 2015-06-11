#ifndef NULL_TEST_HPP
#define NULL_TEST_HPP

#include <cstddef>

static const int dummyVariable = 0;

static const void* dummyPointer = &dummyVariable;
static const void* nullPointer = NULL;

#endif
