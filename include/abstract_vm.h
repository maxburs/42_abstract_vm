#ifndef ABSTRACT_VM_H_
# define ABSTRACT_VM_H_

class AbstractVM
{
    public:
        AbstractVM(void);
        AbstractVM(AbstractVM const &target);
        ~AbstractVM(void);
        AbstractVM &operator=(AbstractVM const &target);

        void run(void);
};

#endif
