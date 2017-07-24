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

//can cause double free
Parser::Parser(Parser const &target) : _operand(target._operand) {}

//this can too
Parser &Parser::operator=(Parser const &target)
{
    this->_operand = target._operand;
    
    return *this;
}

Parser::Parser(void) : _operand(nullptr) {}

Parser::~Parser(void)
{
    delete this->_operand;
}

eInstructionType Parser::nextInstructionType(void)
{
    //todo: main logic goes here

    return Exit;
}

IOperand const *Parser::getOperand(void)
{
    IOperand const *return_me = this->_operand;

    this->_operand = nullptr;
    return return_me;
}
