#ifndef PARSER_H_
# define PARSER_H_

# include <ioperand.h> //IOperand, eOperandType
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
    static const std::string _instructions[];
    static const std::string _values[];
    IOperand const *operand;

public:
    Parser(void);
    Parser(Parser const &target);
    ~Parser(void);
    Parser &operator=(Parser const &target);


    eInstructionType nextInstructionType(void);

    IOperand const *getOperand(void);
};

#endif
