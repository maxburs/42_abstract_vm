#ifndef IOPERAND_H_
# define IOPERAND_H_

# include <string>

enum eOperandType
{
    Int8 = 0,
    Int16 = 1,
    Int32 = 2,
    Float = 3,
    Double = 4
};

class IOperand
{
public:
    virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
    virtual eOperandType getType( void ) const = 0; // Type of the instance

    virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
    virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
    virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
    virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

    virtual std::string const & toString( void ) const = 0; // String representation of the instance

    virtual ~IOperand( void ) {}
};

#endif
