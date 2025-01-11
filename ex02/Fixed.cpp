
#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & _new)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(_new.getRawBits());
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
	    this->_value = copy.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_bits);
}

int Fixed::getRawBits( void )const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return(this->_value);
}

void Fixed::setRawBits( int const value )
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = value;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed before = *this;
	++this->_value;
	return (before);
}

Fixed	Fixed::operator--(int)
{
	Fixed before = *this;
	--this->_value;
	return (before);
}

Fixed	&Fixed::min(Fixed &object1, Fixed &object2)
{
	if (object1.toFloat() <= object2.toFloat())
		return (object1);
	else
		return (object2);
}

const Fixed	&Fixed::min(const Fixed &object1, const Fixed &object2)
{
	if (object1.toFloat() <= object2.toFloat())
		return (object1);
	else
		return (object2);
}

Fixed	&Fixed::max(Fixed &object1, Fixed &object2)
{
	if (object1.toFloat() >= object2.toFloat())
		return (object1);
	else
		return (object2);
}

const Fixed	&Fixed::max(const Fixed &object1, const Fixed &object2)
{
	if (object1.toFloat() >= object2.toFloat())
		return (object1);
	else
		return (object2);
}
