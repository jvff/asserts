#ifndef FORMATTER_HPP
#define FORMATTER_HPP

template <typename T>
class Formatter;

template <typename T>
std::ostream& operator<<(std::ostream&, const Formatter<T>&);

template <typename T>
class Formatter {
    friend std::ostream& operator<< <T>(std::ostream&, const Formatter<T>&);

private:
    const T& value;

public:
    Formatter(const T& parameter) : value(parameter) {
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Formatter<T>& formatter) {
    stream << formatter.value;

    return stream;
}

template <typename T>
Formatter<T> format(const T& value) {
    return Formatter<T>(value);
}

#endif
