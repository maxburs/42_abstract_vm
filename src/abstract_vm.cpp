#include <abstract_vm.h>

#include <ioperand.h> //eOperandType, IOperand
#include <operand.h> //Operand
#include <operand_factory.h> //OperandFactory
#include <parser.h> //Parser, eInstructionType
#include <algorithm> //for_each

#include <vector> //vector

#include <iostream> //cout

void (AbstractVM::* const AbstractVM::_instructions[])(void) = {
    &AbstractVM::_push,
    &AbstractVM::_pop,
    &AbstractVM::_dump,
    &AbstractVM::_assert,
    &AbstractVM::_add,
    &AbstractVM::_sub,
    &AbstractVM::_mul,
    &AbstractVM::_div,
    &AbstractVM::_mod,
    &AbstractVM::_print,
};

void AbstractVM::_push(void)
{
    this->_vector.push_back(this->_parser.getOperand());
}

void AbstractVM::_pop(void)
{
    delete this->_vector.back();
    this->_vector.pop_back();
}

void AbstractVM::_assert(void)
{
    IOperand const *op = this->_parser.getOperand();

    if (this->_vector.front()->toString() != op->toString())
    {
        delete op;
        throw std::exception(); //todo: specialize
    }
    delete op;
}

void AbstractVM::_add(void)
{
    IOperand const *first;
    IOperand const *second;

    first = this->_vector.back();
    this->_vector.pop_back();
    second = this->_vector.back();
    this->_vector.pop_back();

    this->_vector.push_back((*first + *second));
}

void AbstractVM::_sub(void)
{
    IOperand const *first;
    IOperand const *second;

    first = this->_vector.back();
    this->_vector.pop_back();
    second = this->_vector.back();
    this->_vector.pop_back();

    this->_vector.push_back((*first - *second));
}

void AbstractVM::_mul(void)
{
    IOperand const *first;
    IOperand const *second;

    first = this->_vector.back();
    this->_vector.pop_back();
    second = this->_vector.back();
    this->_vector.pop_back();

    this->_vector.push_back((*first * *second));
}

void AbstractVM::_div(void)
{
    IOperand const *first;
    IOperand const *second;

    first = this->_vector.back();
    this->_vector.pop_back();
    second = this->_vector.back();
    this->_vector.pop_back();

    this->_vector.push_back((*first / *second));
}

void AbstractVM::_mod(void)
{
    IOperand const *first;
    IOperand const *second;

    first = this->_vector.back();
    this->_vector.pop_back();
    second = this->_vector.back();
    this->_vector.pop_back();

    this->_vector.push_back((*first % *second));
}

void AbstractVM::_print(void)
{
    if (this->_vector.back()->getType() != Int8)
        throw std::exception(); //todo: specialize

    //todo: fix this
    std::cout << this->_vector.back()->toString() << "\n";
}

void AbstractVM::_dump(void)
{
    auto j = this->_vector.end();
    for (auto i = this->_vector.begin(); i != j; i++)
    {
        std::cout << **i << "\n";
    }
}

AbstractVM::AbstractVM(void) : _vector() {}
//todo: fix constructors
AbstractVM::AbstractVM(AbstractVM const &target) :
    _vector(target._vector) {}

AbstractVM::~AbstractVM(void)
{
    for_each(this->_vector.begin(), this->_vector.end(), [](IOperand const *op) {
        delete op;
    });
}

AbstractVM &AbstractVM::operator=(AbstractVM const &target)
{
    this->_vector = target._vector;;

    return *this;
}

void AbstractVM::run(void)
{
    eInstructionType type;

    while (Exit != (type = this->_parser.nextInstructionType()))
    {
        (this->*AbstractVM::_instructions[type])();
    }
}
