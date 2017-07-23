#ifndef INT8_H_
# define INT8_H_

# include <ioperand.h>
# include <string> //string
# include <cstdint> //int8_t
# include <sstream> //stringstream

template <typename T>
class Operand : public IOperand
{
private:
    std::string _value;
    Operand<T>(void) : _value("0") {}

public:
    Operand<T>(Operand<T> const &target) : _value(target._value) {}
    Operand<T>(std::string const &value)
    {
        std::stringstream ss;

        ss << value;
        this->_value << ss;
    }
    virtual ~Operand<T>(void) {}
    Operand<T> &operator=(Operand<T> const &target);

    int getPrecision(void) const
    {
        return this->getType();
    }
    eOperandType getType( void ) const;

    IOperand const * operator+( IOperand const & rhs ) const
    {
        T rhs_value;
        T this_value;
        std::stringstream ss;

        if (this->getPrecision() < rhs.getPrecision())
        {
            return rhs + *this;
        }
        else
        {
            ss << this->_value;
            this_value << ss;
            ss << rhs->toString;
            rhs_value << ss;
            this_value += rhs_value;
            ss << this_value;
            return new Operand<T>(ss.str());
        }
    }
    IOperand const * operator-( IOperand const & rhs ) const; // Difference
    IOperand const * operator*( IOperand const & rhs ) const; // Product
    IOperand const * operator/( IOperand const & rhs ) const; // Quotient
    IOperand const * operator%( IOperand const & rhs ) const; // Modulo

    std::string const &toString(void) const
    {
        std::stringstream ss;

        ss << this->_value;
        return ss.str();
    }
};
/*
template <>
Operand<int8_t>::Operand<int8_t>(std::string const &value) :
    _value(std::stoi(value)) {}
*/
template <>
eOperandType Operand<int8_t>::getType(void) const
{
    return Int8;
}

#endif
