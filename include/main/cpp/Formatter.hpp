#ifndef FORMATTER_HPP
#define FORMATTER_HPP

template <typename T>
class Formatter {
public:
    Formatter(const T&) {
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Formatter<T>&) {
    stream << 2;

    return stream;
}

template <typename T>
Formatter<T> format(const T& value) {
    return Formatter<T>(value);
}

#endif
