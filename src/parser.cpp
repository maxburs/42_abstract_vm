#include <parser.h>

#include <operand_factory.h> //OperandFactory
#include <ioperand.h> //eOperandType

#include <string> //string, getline(), size_t
#include <map> //map
#include <regex>
#include <iostream> //cin

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

Parser::Parser(Parser const &target) :
    _operand(nullptr),
    _instr_input(target._instr_input)
    {}

//does nothing
Parser &Parser::operator=(Parser const &target)
{
    (void)target;
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

Parser::Parser(std::istream &instr_input) :
    _operand(nullptr),
    _instr_input(instr_input)
    {}
Parser::Parser(void) : Parser(std::cin) {}

Parser::~Parser(void)
{
    delete this->_operand;
}

eInstructionType Parser::nextInstructionType(void)
{
    std::string line;
    
    do {
        std::getline(this->_instr_input, line);
    } while (
        //skips comments
        line[0] == ';'
        && line[1] != ';'
    );

    return this->parseLine(line);
}

eInstructionType Parser::parseLine(std::string line) {
    
    auto split = line.find(" ");
    std::string instruction;

    //if a space was found split the instruction
    if (split != std::string::npos)
    {
        this->_createOperand(line.substr(split + 1));
        instruction = line.substr(0, split);
    }
    else
    {
        instruction = line;
    }

    auto got = Parser::_instructions.find(instruction);
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
