#ifndef ABSTRACT_VM_H_
# define ABSTRACT_VM_H_

# include <vector> //vector
# include <ioperand.h> //IOperand
#include <parser.h> //Parser

class AbstractVM
{
private:
    std::vector<IOperand*> _vector;
    Parser _parser;

public:
    AbstractVM(void);
    AbstractVM(AbstractVM const &target);
    virtual ~AbstractVM(void);
    AbstractVM &operator=(AbstractVM const &target);

    void run(void);
};

#endif
