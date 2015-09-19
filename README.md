# asserts #

## Summary

asserts is a simple library that offers assertion expressions that can
be used with Google Test in order to write more readable code.

## Dependencies

To use the library, the Google Test library and the
[PEGTL library](https://github.com/colinh/pegtl) are required.

To run the test cases, you will need Java to run the Gradle build
system. Gradle itself isn't needed, because the wrapper script should
download the appropriate version of it automatically. You will also need
the [mtrace_gtest library](https://bitbucket.org/jvff/mtrace_gtest). You
can set the path to the `libgtest.a`, `libmtrace_gtest.a` and
`libmtrace_gtest_main.a` libraries, and to the PEGTL headers in the
build.gradle` file.

## Compiling

The library is only made of header files, so compiling it separately is
not necessary.

## Testing

You can run all of the built-in tests running the command

    ./gradlew test

## Usage

To use the library, all you have to do is include the `asserts.hpp`
header file.

```
#include <tuple>

#include <gtest/gtest.h>

#include "asserts.hpp"

TEST(TestCase, firstTest) {
    int value = 3;

    assertThat(value).isEqualTo(3);
    assertThat(value).isLessThan(10);
}

TEST(TestCase, secondTest) {
    AssertThat<std::tuple<int, char> >::isConstructible(With<int, char>());
    AssertThat<std::tuple<> >::isConstructible(WithoutParameters());
}

TEST(TestCase, thirdTest) {
    int value = 3;
    int& reference = value;

    assertThat(reference).isAtSameAddressAs(value);
}
```

## Contributing

Feel free to send feedback, questions, suggestions, fixes, bug reports,
or anything else you think can help this project.

If you provide code, my only request is to also provide test cases of
what is being done and/or what bugs were fixed (ie. a test that fails
without the new code and passes with the new code).

Personally, I develop using TDD, so I would recommend that. However,
feel free to add tests after development if you prefer. I might reorder
the commits to push the tests first though. Also keep the tests small.
I'd rather have a million small and focused tests than one that does the
same thing but makes it hard to isolate future problems.
