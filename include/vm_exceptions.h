#ifndef EXCEPTIONS_H_
# define EXCEPTIONS_H_

# include <exception>
# include <string>

class VMException : public std::exception {
private:
    std::string const _msg;

public:
    VMException(std::string msg)
        : _msg(msg)
    {}

    virtual const char* what(void) const throw()
    {
        return this->_msg.c_str();
    }
};

class AssertException : public VMException {
public:
    AssertException() : VMException(
        "An assert instruction is not true"
    ) {}
};

class PopException : public VMException {
public :
    PopException(
    ) : VMException(
        "Pop on empty stack"
    ) {}
};

// thrown when there are not enough values on
//     the stack to perform a math operation
class StackSizeException : public VMException {
public:
    StackSizeException(
        std::string instruction,
        int stack_size
    ) : VMException(
        instruction + " on stack of size " + std::to_string(stack_size)
    ) {}

};

// thrown if the number on the top of the stack is not of type int8
// todo: give more information in error
class PrintException : public VMException {
public:
    PrintException() : VMException(
        "Operand on the top of the stack is not of type int8"
    ) {}
};

class UnknownInstructionException : public VMException {
public:
    UnknownInstructionException() : VMException (
        "an instruction is unknown"
    ) {}
};

#endif
