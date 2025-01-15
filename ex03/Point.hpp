#ifndef POINT_HPP

# define POINT_HPP

# include <string>
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
private:
	const Fixed	x_value; // To store the fixed-point number value.
    const Fixed	y_value; // To store the fixed-point number value.

public:
	//Default
	Point();

	//2 param constructor
	Point(const float x, const float y);

	//Copy constructor
	Point(const Point &other);

    // Copy assignment operator
	Point &operator=(const Point &other);

	//Destructor
	~Point();

	//getX
    Fixed getX() const;

    //getY
    Fixed getY() const;
};


#endif