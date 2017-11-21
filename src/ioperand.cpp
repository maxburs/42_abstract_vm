#include <ioperand.h> //IOperand
#include <string> //string

std::ostream &operator<<(std::ostream &os, IOperand const &op)
{
    os << op.toString();
    return os;
}
