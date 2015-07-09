#ifndef IS_PRINTABLE_TEST_HPP
#define IS_PRINTABLE_TEST_HPP

#include <iostream>

class UnprintableClass {
};

class PrintableClass {
};

std::ostream& operator<<(std::ostream&, const PrintableClass&);

#endif
