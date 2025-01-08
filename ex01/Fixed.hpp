
#ifndef FIXED_HPP
# define FIXED_HPP

#include  <iostream>
#include  <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(Fixed const &_new);
        Fixed(const int value);
        Fixed(const float value);
        Fixed	&operator=(Fixed const &copy);
        int getRawBits() const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        ~Fixed();
};

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed);


#endif