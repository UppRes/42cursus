#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_rawbits;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(Fixed const &);
		~Fixed();
		Fixed& operator=(Fixed const &);

			//* Bool Operators
		bool	operator>(const Fixed &) const;
		bool	operator<(const Fixed &) const;
		bool	operator>=(const Fixed &) const;
		bool	operator<=(const Fixed &) const;
		bool	operator==(const Fixed &) const;
		bool	operator!=(const Fixed &) const;

		//* Arithmetic Operators
		Fixed	operator+(const Fixed &) const;
		Fixed	operator-(const Fixed &) const;
		Fixed	operator*(const Fixed &) const;
		Fixed	operator/(const Fixed &) const;

		//* Increment & Decrement Operators
		// *- prefix -*
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		// *- postfix -*
		Fixed	operator++(int);
		Fixed	operator--(int);

		//* Min & Max
		static Fixed		&min(Fixed &, Fixed &);
		static const Fixed	&min(const Fixed &, const Fixed &);
		static Fixed		&max(Fixed &, Fixed &);
		static const Fixed	&max(const Fixed &, const Fixed &);

		void		setRawBits(const int);
		int			getRawBits() const;

		float		toFloat( void ) const;
		int			toInt( void ) const;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& Fixed);