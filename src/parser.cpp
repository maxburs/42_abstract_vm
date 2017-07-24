#include <parser.h>

#include <string> //string

std::string const Parser::_instructions[] = {
    "push",
    "pop",
    "dump",
    "assert",
    "add",
    "sub",
    "mul",
    "div",
    "mod",
    "print",
    "exit"
};

std::string const Parser::_values[] = {
    "int8",
    "int16",
    "int32",
    "float",
    "double"
};
