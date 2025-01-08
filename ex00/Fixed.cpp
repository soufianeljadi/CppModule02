
#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & _new)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(_new.getRawBits());
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void )const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
