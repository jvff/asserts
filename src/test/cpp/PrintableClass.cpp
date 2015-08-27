#include "PrintableClass.hpp"

std::ostream& operator<<(std::ostream& outputStream,
        const PrintableClass& instance) {
    return outputStream << "PrintableClass@" << (void*)&instance;
}
