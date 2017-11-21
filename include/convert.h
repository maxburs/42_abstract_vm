#ifndef CONVERT_H_
# define CONVERT_H_

# include <string> // string, to_string()
# include <sstream> // stringstream
# include <cstdint> // int8_t, int32_t
# include <iostream> // fixed
# include <iomanip> // setprecision

template <typename T>
T from_string(std::string const &str) {
    T value;
    std::stringstream ss;

    ss << str;
    ss >> value;
    return value;
}

template <>
inline int8_t from_string(std::string const &str) {
    int32_t value;
    std::stringstream ss;

    ss << str;
    ss >> value;
    return (int8_t)value;
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
