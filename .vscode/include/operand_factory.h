#ifndef OPERAND_FACTORY_H_
# define OPERAND_FACTORY_H_

# include <operand.h> //Operand
# include <ioperand.h> //IOperand, eOperandtype

class OperandFactory
{
    private:
        IOperand const *createInt8(std::string const &value) const;
        IOperand const *createInt16(std::string const &value) const;
        IOperand const *createInt32(std::string const &value) const;
        IOperand const *createFloat(std::string const &value) const;
        IOperand const *createDouble(std::string const &value) const;

    public:
        IOperand const * createOperand( eOperandType type, std::string const &value ) const;
};

#endif
