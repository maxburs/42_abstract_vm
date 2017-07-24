#ifndef PARSER_H_
# define PARSER_H_

# include <ioperand.h> //IOperand, eOperandType
# include <operand_factory.h> //OperandFactory
# include <string> //string

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

    static const std::string _instructions[];
    static const std::string _values[];
    static OperandFactory const _factory;
    IOperand const *_operand;

public:
    Parser(void);
    ~Parser(void);

    eInstructionType nextInstructionType(void);

    IOperand const *getOperand(void);
};

#endif
