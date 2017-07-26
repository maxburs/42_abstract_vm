#include <parser.h>

#include <operand_factory.h> //OperandFactory
#include <ioperand.h> //eOperandType

#include <string> //string, getline(), size_t
#include <map> //map
#include <regex>

/* no longer being used //todo: remove

std::string const Parser::_instructions_s[] = {
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

std::string const Parser::_types_s[] = {
    "int8",
    "int16",
    "int32",
    "float",
    "double"
};
*/

std::unordered_map<std::string, eInstructionType> const Parser::_instructions = {
    {"push", Push},
    {"pop", Pop},
    {"dump", Dump},
    {"assert", Assert},
    {"add", Add},
    {"sub", Sub},
    {"mul", Mul},
    {"div", Div},
    {"mod", Mod},
    {"print", Print},
    {"exit", Exit}
};

std::unordered_map<std::string, eOperandType> const Parser::_types = {
    {"int8", Int8},
    {"int16", Int16},
    {"int32", Int32},
    {"float", Float},
    {"double", Double}
};

OperandFactory const Parser::_operandFactory = {};

//can cause double free
Parser::Parser(Parser const &target) : _operand(target._operand) {}

//this can too
Parser &Parser::operator=(Parser const &target)
{
    this->_operand = target._operand;
    
    return *this;
}

//creates operand from op part of instr; ex: int8(4)
void Parser::_createOperand(std::string operand)
{
    std::size_t split;
    eOperandType type = Float;

    //validate format
    if (std::regex_match(operand, std::regex("\\w+\\d*\\(\\d+\\.?\\d*\\)")) == false)
        throw std::exception();
    
    split = operand.find("(");

    auto got = Parser::_types.find(operand.substr(0, split));
    if (got == Parser::_types.end())
        throw std::exception(); //todo: make appropriate type

    type = got->second;

    delete this->_operand;
    this->_operand = Parser::_operandFactory.createOperand(
        type,
        operand.substr(split + 1, operand.length() - split - 2) );
}

Parser::Parser(void) : _operand(nullptr) {}

Parser::~Parser(void)
{
    delete this->_operand;
}

eInstructionType Parser::nextInstructionType(void)
{
    std::string instr;
    std::size_t split;
    
    std::getline(std::cin, instr);

    split = instr.find(" ");

    //if a space was found split the instruction
    if (split != std::string::npos)
    {
        this->_createOperand(instr.substr(split + 1));
        instr = instr.substr(0, split);
    }

    auto got = Parser::_instructions.find(instr);
    if (got == Parser::_instructions.end())
        throw std::exception(); //todo: make exception an apropriate type

    return got->second;
}

IOperand const *Parser::getOperand(void)
{
    IOperand const *return_me = this->_operand;

    this->_operand = nullptr;
    return return_me;
}