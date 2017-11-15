#ifndef ABSTRACT_VM_H_
# define ABSTRACT_VM_H_

# include <vector> //vector
# include <ioperand.h> //IOperand
# include <parser.h> //Parser
# include <iostream> //istream, cin
# include <operand_factory.h> //OperandFactory

class AbstractVM
{
private:
    std::vector<IOperand const *> _vector;
    Parser _parser;

    static void (AbstractVM::* const _instructions[])(void);

    void _push(void);
    void _pop(void);
    void _dump(void);
    void _assert(void);
    void _add(void);
    void _sub(void);
    void _mul(void);
    void _div(void);
    void _mod(void);
    void _print(void);

public:
    AbstractVM(std::istream &instr_input);
    AbstractVM(void);
    AbstractVM(AbstractVM const &target);
    virtual ~AbstractVM(void);
    AbstractVM &operator=(AbstractVM const &target);

    // returns 1 if an error is found
    int run(void);
};

#endif
