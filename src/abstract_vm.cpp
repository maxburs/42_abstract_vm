#include <abstract_vm.h>
#include <operand.h>
#include <stack> //stack

#include <iostream>


AbstractVM::AbstractVM(void) {}

AbstractVM::AbstractVM(AbstractVM const &target) {}

AbstractVM::~AbstractVM(void) {}

AbstractVM &AbstractVM::operator=(AbstractVM const &target)
{
    return *this;
}

void AbstractVM::run(void)
{
    std::cout << "hello world\n";
}