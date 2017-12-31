#ifndef OPERAND_FACTORY_H_
# define OPERAND_FACTORY_H_

# include <operand.h> // Operand
# include <ioperand.h> // IOperand, eOperandtype
# include <convert.h> // from_string

class OperandFactory
{
    private:
        template <typename T>
        Operand<T> const *createSpecific(std::string const &value) const;
        IOperand const *createInt8(std::string const &value) const;
        IOperand const *createInt16(std::string const &value) const;
        IOperand const *createInt32(std::string const &value) const;
        IOperand const *createFloat(std::string const &value) const;
        IOperand const *createDouble(std::string const &value) const;

    public:
        IOperand const * createOperand(eOperandType type, std::string const &value) const;
};

template <typename T>
inline Operand<T> const *OperandFactory::createSpecific(std::string const &value) const
{
    return new Operand<T>(from_string<T>(value));
}

#endif
