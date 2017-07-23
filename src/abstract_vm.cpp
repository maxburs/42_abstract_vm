#include <abstract_vm.h>
#include <operand.h>
#include <stack> //stack

#include <iostream>


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
    Operand<int8_t> const a("5");
    Operand<double> const b("7.001");
    IOperand const *c = a + b;

    std::cout << "a: " << a.toString() << "\n";
    std::cout << "b: " << b.toString() << "\n";
    std::cout << "c: " << c->toString() << "\n";

    delete c;

    c = b - a;
    std::cout << "c: " << c->toString() << "\n";
}
