#include <abstract_vm.h>

#include <ioperand.h> //eOperandType, IOperand
#include <operand.h> //Operand
#include <operand_factory.h> //OperandFactory
#include <parser.h> //Parser

#include <vector> //vector

#include <iostream> //cout


AbstractVM::AbstractVM(void) : _vector() {}

AbstractVM::AbstractVM(AbstractVM const &target) : _vector(target._vector) {}

AbstractVM::~AbstractVM(void)
{
    //TODO
}

AbstractVM &AbstractVM::operator=(AbstractVM const &target)
{
    this->_vector = target._vector;;

    return *this;
}

void AbstractVM::run(void)
{
    eInstructionType type;
    IOperand const *op = nullptr;

    while (Exit != (type = this->_parser.nextInstructionType()))
    {
        std::cout << "instr: " << type << "\n";
        op = this->_parser.getOperand();
        if (op)
            std::cout << *op << "\n";
        delete op;
    }
}
