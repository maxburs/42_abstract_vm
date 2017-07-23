#ifndef ABSTRACT_VM_H_
# define ABSTRACT_VM_H_

# include <stack> //stack
# include <ioperand.h>

class AbstractVM
{
private:
    std::stack<IOperand*> _stack;

public:
    AbstractVM(void);
    AbstractVM(AbstractVM const &target);
    virtual ~AbstractVM(void);
    AbstractVM &operator=(AbstractVM const &target);

    void run(void);
};

#endif
