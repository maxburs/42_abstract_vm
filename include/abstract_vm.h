#ifndef ABSTRACT_VM_H_
# define ABSTRACT_VM_H_

# include <vector> //vector
# include <ioperand.h>

class AbstractVM
{
private:
    std::vector<IOperand*> _vector;

public:
    AbstractVM(void);
    AbstractVM(AbstractVM const &target);
    virtual ~AbstractVM(void);
    AbstractVM &operator=(AbstractVM const &target);

    void run(void);
};

#endif
