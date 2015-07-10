#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include "IsPrintable.hpp"
#include "TypeOf.hpp"

template <typename T>
class Formatter;

template <typename T>
typename std::enable_if<IsPrintable<T>::value, std::ostream&>::type
	operator<<(std::ostream&, const Formatter<T>&);

template <typename T>
typename std::enable_if<!IsPrintable<T>::value, std::ostream&>::type
	operator<<(std::ostream&, const Formatter<T>&);

template <typename T>
class Formatter {
    friend std::ostream& operator<< <T>(std::ostream&, const Formatter<T>&);

private:
    const T& value;

public:
    Formatter(const T& parameter) : value(parameter) {
    }
};

template <>
class Formatter<bool> {
    friend std::ostream& operator<< <bool>(std::ostream&,
            const Formatter<bool>&);

private:
    std::string value;

public:
    Formatter(bool parameter) {
        if (parameter == true)
            value = "true";
        else
            value = "false";
    }
};

template <typename T>
typename std::enable_if<IsPrintable<T>::value, std::ostream&>::type
	operator<<(std::ostream& stream, const Formatter<T>& formatter) {
    stream << formatter.value;

    return stream;
}

template <typename T>
typename std::enable_if<!IsPrintable<T>::value, std::ostream&>::type
	operator<<(std::ostream& stream, const Formatter<T>& formatter) {
    stream << "?(" << TypeOf<T>() << "@" << (void*)&formatter.value << ")";

    return stream;
}

template <typename T>
Formatter<T> format(const T& value) {
    return Formatter<T>(value);
}

#endif
