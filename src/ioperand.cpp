#include <ioperand.h> //IOperand
#include <string> //string

std::ostream &operator<<(std::ostream &os, IOperand const &op)
{
    static std::string const string_representation[] = {
        "Int8",
        "Int16",
        "Int32",
        "Float",
        "Double"
    };

    os << string_representation[op.getType()] << ": " << op.toString();
    return os;
}
