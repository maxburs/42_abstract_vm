#ifndef INT8_H_
# define INT8_H_

# include <ioperand.h> //IOperand, eOperandtype
# include <string> //string
# include <cstdint> //int8_t
# include <sstream> //stringstream
# include <convert.h> //toString()
# include <algorithm> //max()
# include <exception> //exception

template <typename T>
class Operand : public IOperand
{
private:
    std::string _value;
    Operand<T>(void) : _value("0") {}

public:
    Operand<T>(Operand<T> const &target) : _value(target._value) {}
    Operand<T>(std::string const &value) : _value(value) {}
    virtual ~Operand<T>(void) {}
    Operand<T> &operator=(Operand<T> const &target)
    {
        this->_value = target._value;
        return *this;
    }

    int getPrecision(void) const
    {
        return this->getType();
    }
    eOperandType getType( void ) const;

    IOperand const * operator+( IOperand const & rhs ) const
    {
        std::stringstream ss;

        if (this->getPrecision() < rhs.getPrecision())
            return rhs + *this;
        
        ss << from_string<T>(this->toString()) + from_string<T>(rhs.toString());
        return new Operand<T>(ss.str());
    }
    IOperand const * operator-( IOperand const & rhs ) const
    {
        std::stringstream ss;
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());
        
        switch (precision)
        {
            case Int8:
                ss << from_string<int8_t>(this->toString()) - from_string<int8_t>(rhs.toString());
                break ;
            case Int16:
                ss << from_string<int16_t>(this->toString()) - from_string<int16_t>(rhs.toString());
                break ;
            case Int32:
                ss << from_string<int32_t>(this->toString()) - from_string<int32_t>(rhs.toString());
                break ;
            case Float:
                ss << from_string<float>(this->toString()) - from_string<float>(rhs.toString());
                break ;
            case Double:
                ss << from_string<double>(this->toString()) - from_string<double>(rhs.toString());
                break ;
        }
        return new Operand<T>(ss.str());
    }
    IOperand const * operator*( IOperand const & rhs ) const
    {
        std::stringstream ss;

        if (this->getPrecision() < rhs.getPrecision())
            return rhs * *this;
        
        ss << from_string<T>(this->toString()) * from_string<T>(rhs.toString());
        return new Operand<T>(ss.str());
    }
    IOperand const * operator/( IOperand const & rhs ) const
    {
        std::stringstream ss;
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());

        //TODO: check for divion by zero

        switch (precision)
        {
            case Int8:
                ss << from_string<int8_t>(this->toString()) / from_string<int8_t>(rhs.toString());
                break ;
            case Int16:
                ss << from_string<int16_t>(this->toString()) / from_string<int16_t>(rhs.toString());
                break ;
            case Int32:
                ss << from_string<int32_t>(this->toString()) / from_string<int32_t>(rhs.toString());
                break ;
            case Float:
                ss << from_string<float>(this->toString()) / from_string<float>(rhs.toString());
                break ;
            case Double:
                ss << from_string<double>(this->toString()) / from_string<double>(rhs.toString());
                break ;
            default:
                throw std::exception();
        }
        return new Operand<T>(ss.str());
    }
    IOperand const * operator%( IOperand const & rhs ) const
    {
        std::stringstream ss;
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());
        
        //TODO: check for divion by zero
        
        switch (precision)
        {
            case Int8:
                ss << from_string<int8_t>(this->toString()) % from_string<int8_t>(rhs.toString());
                break ;
            case Int16:
                ss << from_string<int16_t>(this->toString()) % from_string<int16_t>(rhs.toString());
                break ;
            case Int32:
                ss << from_string<int32_t>(this->toString()) % from_string<int32_t>(rhs.toString());
                break ;
            default:
                throw std::exception();
        }
        return new Operand<T>(ss.str());
    }

    std::string const &toString(void) const
    {
        return this->_value;
    }
};

template <>
eOperandType Operand<int8_t>::getType(void) const
{
    return Int8;
}

template <>
eOperandType Operand<int16_t>::getType(void) const
{
    return Int16;
}

template <>
eOperandType Operand<int32_t>::getType(void) const
{
    return Int32;
}

template <>
eOperandType Operand<float>::getType(void) const
{
    return Float;
}

template <>
eOperandType Operand<double>::getType(void) const
{
    return Double;
}

#endif
