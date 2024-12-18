#ifndef FIXED_POINT_HPP

# define FIXED_POINT_HPP

# include <string>
# include <iostream>
# include <cmath>
class Fixed
{
private:
	int	value; // To store the fixed-point number value.
	static const int fractionalBits = 8;  // Number of fractional bits.

public:
	//Default
	Fixed();

	//Copy constructor
	Fixed(const Fixed &other);

	//int constructor
	Fixed(const int intValue);

	//float constructor
	Fixed(const float floatValue);

    // Copy assignment operator
	Fixed &operator=(const Fixed &other);

	//Destructor
	~Fixed();

	// Member function to get the raw value
	int getRawBits(void) const;

    // Member function to set the raw value
	void setRawBits(int const raw);

    // Converts the fixed-point value to a floating-point value
    float toFloat() const;

    // Converts the fixed-point value to an integer value
    int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fp);


#endif