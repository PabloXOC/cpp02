#include "Fixed.hpp"

Fixed::Fixed() :
value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) :
value(other.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) :
value(intValue << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) :
value(static_cast<int>(roundf(floatValue * (1 << fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {

        value = other.value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout <<"getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fp)
{
    out << fp.toFloat();
    return out;
}
