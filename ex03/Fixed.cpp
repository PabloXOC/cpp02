#include "Fixed.hpp"

Fixed::Fixed() :
value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) :
value(other.value)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) :
value(intValue << fractionalBits)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) :
value(static_cast<int>(roundf(floatValue * (1 << fractionalBits))))
{
    //std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {

        value = other.value;
    }
    return *this;
}

Fixed::~Fixed()
{
    //std::cout <<"Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    //std::cout <<"getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed &other) const
{
    if (value > other.value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &other) const
{
    if (value < other.value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (value >= other.value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (value <= other.value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &other) const
{
    if (value == other.value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (value != other.value)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() { // Pre-increment
    value++;
    return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
    Fixed temp = *this;
    value++;
    return temp;
}

Fixed &Fixed::operator--() { // Pre-decrement
    value--;
    return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
    Fixed temp = *this;
    value--;
    return temp;
}

// Static Functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
