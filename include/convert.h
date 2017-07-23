#ifndef CONVERT_H_
# define CONVERT_H_

# include <string>
# include <sstream>
# include <cstdint>

template <typename T>
T from_string(std::string const &str)
{
    T value;
    std::stringstream ss;

    ss << str;
    ss >> value;
    return value;
}

template <>
int8_t from_string(std::string const &str)
{
    int32_t value;
    std::stringstream ss;

    ss << str;
    ss >> value;
    return (int8_t)value;
}

#endif
