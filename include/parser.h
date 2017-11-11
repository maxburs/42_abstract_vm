#ifndef PARSER_H_
# define PARSER_H_

# include <ioperand.h> //IOperand, eOperandType
# include <operand_factory.h> //OperandFactory
# include <string> //string
# include <unordered_map> //map
# include <istream> //istream

enum eInstructionType
{
    Push,
    Pop,
    Dump,
    Assert,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    Print,
    Exit
};

class Parser
{
private:
    Parser(Parser const &target); //can cause double free
    Parser &operator=(Parser const &target); //this can too

    static std::string const _instructions_s[];
    static std::string const _types_s[];
    static std::unordered_map<std::string, eInstructionType> const _instructions;
    static std::unordered_map<std::string, eOperandType> const _types;

    static OperandFactory const _operandFactory;
    IOperand const *_operand;
    std::istream &_instr_input;

    void _createOperand(std::string operand);
    eInstructionType parseLine(std::string);

public:
    Parser(std::istream &instr_input);
    Parser(void);
    ~Parser(void);

    eInstructionType nextInstructionType(void);

    IOperand const *getOperand(void);
};

#endif
