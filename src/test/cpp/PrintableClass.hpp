#ifndef PRINTABLE_CLASS_HPP
#define PRINTABLE_CLASS_HPP

#include <iostream>

class PrintableClass {
};

std::ostream& operator<<(std::ostream&, const PrintableClass&);

#endif
