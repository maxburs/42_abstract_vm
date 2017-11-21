#include <parser.h>

#include <operand_factory.h> //OperandFactory
#include <ioperand.h> //eOperandType
#include <vm_exceptions.h>

#include <string> //string, getline(), size_t, nopos
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
    _instr_input(target._instr_input),
    _alternate_input(target._alternate_input),
    _line_number(target._line_number) {}

//does nothing
Parser &Parser::operator=(Parser const &target) {
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
        throw UnknownInstructionException();

    type = got->second;

    delete this->_operand;
    this->_operand = Parser::_operandFactory.createOperand(
        type,
        operand.substr(split + 1, operand.length() - split - 2) );
}

Parser::Parser(std::istream &instr_input) :
    _operand(nullptr),
    _instr_input(instr_input),
    _alternate_input(true),
    _line_number(0)
{}

Parser::Parser(void) :
    _operand(nullptr),
    _instr_input(std::cin),
    _alternate_input(false),
    _line_number(0)
{}

Parser::~Parser(void) {
    delete this->_operand;
}

eInstructionType Parser::nextInstructionType(void) {
    std::string line;
    
    do {
        if (!std::getline(this->_instr_input, line)) {
            if (this->_instr_input.eof())
                throw ExitException();
            else
                throw VMException("Unknown input read error");
        }
        if (
            this->_alternate_input == false
            && line[0] == ';'
            && line[1] == ';'
        ) {
            throw ExitException();
        }
        this->_line_number++;
    } while (
        //skips comments
        line[0] == ';'
    );

    return this->parseLine(line);
}

eInstructionType Parser::parseLine(std::string line) {
    
    auto split = line.find(" ");
    std::string instruction;

    //if a space was found split the instruction
    if (split != std::string::npos) {
        this->_createOperand(line.substr(split + 1));
        instruction = line.substr(0, split);
    } else {
        instruction = line;
    }

    auto got = Parser::_instructions.find(instruction);
    if (got == Parser::_instructions.end())
        throw UnknownInstructionException();

    return got->second;
}

IOperand const *Parser::getOperand(void) {
    IOperand const *return_me = this->_operand;

    this->_operand = nullptr;
    return return_me;
}

int Parser::getLineNumber(void) {
    return this->_line_number;
}
