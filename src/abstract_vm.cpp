#include <abstract_vm.h>

#include <ioperand.h> //eOperandType, IOperand
#include <operand.h> //Operand
#include <operand_factory.h> //OperandFactory

#include <stack> //stack

#include <iostream> //cout


AbstractVM::AbstractVM(void) : _stack() {}

AbstractVM::AbstractVM(AbstractVM const &target) : _stack(target._stack) {}

AbstractVM::~AbstractVM(void)
{
    //TODO
}

AbstractVM &AbstractVM::operator=(AbstractVM const &target)
{
    this->_stack = target._stack;;

    return *this;
}

void AbstractVM::run(void)
{
    OperandFactory factory;
    Operand<int8_t> const a("5");
    Operand<double> const b("7.001");
    IOperand const *c = a + b;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << *c << "\n";

    delete c;

    c = b - a;
    std::cout << "c: " << *c << "\n";

    IOperand const *d = factory.createOperand(Int16, "10");

    std::cout << "d: " << *d << "\n";
}
