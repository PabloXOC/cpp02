#include "Point.hpp"

Point::Point() :
x_value(0), y_value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : 
x_value(x), y_value(y)
{
    //std::cout << "Constructor with two constant floating-point numbers called" << std::endl;
}

Point::Point(const Point &other) :
x_value(other.x_value), y_value(other.y_value)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {

        const_cast<Fixed &>(this->x_value) = other.x_value;
        const_cast<Fixed &>(this->y_value) = other.y_value;
    }
    return *this;
}

Point::~Point()
{
    //std::cout <<"Destructor called" << std::endl;
}

Fixed Point::getX(void) const
{
    //std::cout <<"getX member function called" << std::endl;
    return x_value;
}

Fixed Point::getY(void) const
{
    //std::cout <<"getY member function called" << std::endl;
    return y_value;
}
