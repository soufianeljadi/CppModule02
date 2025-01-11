
#ifndef FIXED_HPP
# define FIXED_HPP

#include  <iostream>
#include  <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		bool operator>(Fixed fixed)const;
		bool operator<(Fixed fixed)const;
		bool operator>=(Fixed fixed)const;
		bool operator<=(Fixed fixed)const;
		bool operator==(Fixed fixed)const;
		bool operator!=(Fixed fixed)const;
		float operator+(Fixed fixed)const;
		float operator-(Fixed fixed)const;
		float operator*(Fixed fixed)const;
		float operator/(Fixed fixed)const;
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		float toFloat(void)const;
		int toInt(void)const;
		static Fixed &min(Fixed &object1, Fixed &object2);
		static const Fixed &min(Fixed const &object1, Fixed const &object2);
		static Fixed &max(Fixed &object1, Fixed &object2);
		static const Fixed &max(Fixed const &object1, const Fixed &object2);
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif