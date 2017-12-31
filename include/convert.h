#ifndef CONVERT_H_
# define CONVERT_H_

# include <string> // string, to_string()
# include <sstream> // stringstream
# include <cstdint> // int8_t, int32_t
# include <iostream> // fixed
# include <iomanip> // setprecision
# include <vm_exceptions.h> // OverflowException
# include <limits> // max(), min()

template <typename T>
T from_string(std::string const &str) {
    T value;
    std::stringstream ss;

    ss << str;
    ss >> value;

    if (ss.fail())
        throw OverflowException();

    return value;
}

/*
 * from_string function conversion method converts first
 * char when doing int8_t conversions.
*/
template <>
inline int8_t from_string(std::string const &str) {
    auto value = from_string<int32_t>(str);

    if (
        value < std::numeric_limits<int8_t>::min()
        || value > std::numeric_limits<int8_t>::max()
    ) {
        throw OverflowException();
    }
    return value;
}

template <typename T>
std::string to_string(T num) {
    return std::to_string(num);
}

template <>
inline std::string to_string(float num) {
    std::stringstream ss;

    ss << std::fixed << std::setprecision(2) << num;

    return ss.str();
}

template <>
inline std::string to_string(double num) {
    std::stringstream ss;

    ss << std::fixed << std::setprecision(2) << num;

    return ss.str();
}

#endif
