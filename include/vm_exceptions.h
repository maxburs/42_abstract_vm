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
    PrintException(void) : VMException(
        "Operand on the top of the stack is not of type int8"
    ) {}
};

class UnknownInstructionException : public VMException {
public:
    UnknownInstructionException(void) : VMException (
        "an instruction is unknown"
    ) {}
};

class OperationByZeroException : public VMException {
public:
    OperationByZeroException(
        std::string operation
    ) : VMException(
        operation + " by zero"
    ) {}

};

class ModulusWithFloatException : public VMException {
public:
    ModulusWithFloatException(void) : VMException (
        "Cannot perform modulus operation with floating point numbers"
    ) {}
};

class CorruptIOperandException : public VMException {
public:
    CorruptIOperandException(void) : VMException (
        "Invalid ioperand type, possible memory corruption or pointer error"
    ) {}
};

class OverflowException : public VMException {
public:
    OverflowException(void) : VMException (
        "Overflow on a value or the result of an operation"
    ) {}
};

class UnderflowException : public VMException {
public:
    UnderflowException(void) : VMException (
        "Underflow on a value or the result of an operation"
    ) {}
};

class ExitException : public VMException {
public:
    ExitException(void) : VMException (
        "The program doesn’t have an exit instruction"
    ) {}
};

class MissingValueException : public VMException {
public:
    MissingValueException(void) : VMException (
        "Operation requires value"
    ) {}
};

#endif
