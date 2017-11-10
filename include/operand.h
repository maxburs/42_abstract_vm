#ifndef INT8_H_
# define INT8_H_

# include <ioperand.h> //IOperand, eOperandtype
# include <string> //string
# include <cstdint> //int8_t
# include <convert.h> //toString()
# include <algorithm> //max()
# include <exception> //exception

//needs to throw error on bad cast?
template <typename T>
T convertOperand(IOperand const * op);

template <typename T>
class Operand : public IOperand
{
private:
    T _value;
    std::string _string;
    Operand<T>(void) :
        _value(0),
        _string("0")
        {}

public:
    Operand<T>(Operand<T> const &target) :
        _value(target._value),
        _string(target._string)
        {}
    Operand<T>(T const value) :
        _value(value),
        _string(std::to_string(value))
        {}
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
    eOperandType getType(void) const;
    T getValue(void) const {
        return this->_value;
    }

    IOperand const * operator+(IOperand const & rhs) const
    {
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());

        switch (precision)
        {
            case Int8:
                return new Operand<int8_t>(
                    convertOperand<int8_t>(this) + convertOperand<int8_t>(&rhs)
                );
            case Int16:
                return new Operand<int16_t>(
                    convertOperand<int16_t>(this) + convertOperand<int16_t>(&rhs)
                );
            case Int32:
                return new Operand<int32_t>(
                    convertOperand<int32_t>(this) + convertOperand<int32_t>(&rhs)
                );
            case Float:
                return new Operand<float>(
                    convertOperand<float>(this) + convertOperand<float>(&rhs)
                );
            case Double:
                return new Operand<double>(
                    convertOperand<double>(this) + convertOperand<double>(&rhs)
                );
            default:
                throw std::exception();
        }
    }
    IOperand const * operator-(IOperand const & rhs) const
    {
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());

        switch (precision)
        {
            case Int8:
                return new Operand<int8_t>(
                    convertOperand<int8_t>(this) - convertOperand<int8_t>(&rhs)
                );
            case Int16:
                return new Operand<int16_t>(
                    convertOperand<int16_t>(this) - convertOperand<int16_t>(&rhs)
                );
            case Int32:
                return new Operand<int32_t>(
                    convertOperand<int32_t>(this) - convertOperand<int32_t>(&rhs)
                );
            case Float:
                return new Operand<float>(
                    convertOperand<float>(this) - convertOperand<float>(&rhs)
                );
            case Double:
                return new Operand<double>(
                    convertOperand<double>(this) - convertOperand<double>(&rhs)
                );
            default:
                throw std::exception();
        }
    }
    IOperand const * operator*( IOperand const & rhs ) const
    {
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());

        switch (precision)
        {
            case Int8:
                return new Operand<int8_t>(
                    convertOperand<int8_t>(this) * convertOperand<int8_t>(&rhs)
                );
            case Int16:
                return new Operand<int16_t>(
                    convertOperand<int16_t>(this) * convertOperand<int16_t>(&rhs)
                );
            case Int32:
                return new Operand<int32_t>(
                    convertOperand<int32_t>(this) * convertOperand<int32_t>(&rhs)
                );
            case Float:
                return new Operand<float>(
                    convertOperand<float>(this) * convertOperand<float>(&rhs)
                );
            case Double:
                return new Operand<double>(
                    convertOperand<double>(this) * convertOperand<double>(&rhs)
                );
            default:
                throw std::exception();
        }
    }
    //todo: division by zero
    IOperand const * operator/( IOperand const & rhs ) const
    {
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());

        switch (precision)
        {
            case Int8:
                return new Operand<int8_t>(
                    convertOperand<int8_t>(this) / convertOperand<int8_t>(&rhs)
                );
            case Int16:
                return new Operand<int16_t>(
                    convertOperand<int16_t>(this) / convertOperand<int16_t>(&rhs)
                );
            case Int32:
                return new Operand<int32_t>(
                    convertOperand<int32_t>(this) / convertOperand<int32_t>(&rhs)
                );
            case Float:
                return new Operand<float>(
                    convertOperand<float>(this) / convertOperand<float>(&rhs)
                );
            case Double:
                return new Operand<double>(
                    convertOperand<double>(this) / convertOperand<double>(&rhs)
                );
            default:
                throw std::exception();
        }
    }
    //todo: modulus by zero
    IOperand const * operator%( IOperand const & rhs ) const
    {
        auto precision = std::max(this->getPrecision(), rhs.getPrecision());

        switch (precision)
        {
            case Int8:
                return new Operand<int8_t>(
                    convertOperand<int8_t>(this) % convertOperand<int8_t>(&rhs)
                );
            case Int16:
                return new Operand<int16_t>(
                    convertOperand<int16_t>(this) % convertOperand<int16_t>(&rhs)
                );
            case Int32:
                return new Operand<int32_t>(
                    convertOperand<int32_t>(this) % convertOperand<int32_t>(&rhs)
                );
            case Float:
            case Double:
            default:
                throw std::exception();
        }
    }

    std::string const &toString(void) const
    {
        return this->_string;
    }
    T getValue(void)
    {
        return this->_value;
    }
};

template <>
inline eOperandType Operand<int8_t>::getType(void) const
{
    return Int8;
}

template <>
inline eOperandType Operand<int16_t>::getType(void) const
{
    return Int16;
}

template <>
inline eOperandType Operand<int32_t>::getType(void) const
{
    return Int32;
}

template <>
inline eOperandType Operand<float>::getType(void) const
{
    return Float;
}

template <>
inline eOperandType Operand<double>::getType(void) const
{
    return Double;
}

template <typename T>
T convertOperand(IOperand const * op)
{
    switch (op->getPrecision())
    {
        case Int8:
            return ((Operand<int8_t>*)op)->getValue();
        case Int16:
            return ((Operand<int16_t>*)op)->getValue();
        case Int32:
            return ((Operand<int32_t>*)op)->getValue();
        case Float:
            return ((Operand<float>*)op)->getValue();
        case Double:
            return ((Operand<double>*)op)->getValue();
        default:
            throw std::exception();
    }
}

#endif
