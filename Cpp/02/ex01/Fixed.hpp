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
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(Fixed const &Fixed);
		~Fixed();
		Fixed& operator=(Fixed const &Fixed);

		void		setRawBits(const int raw);
		int			getRawBits() const;

		float		toFloat( void ) const;
		int			toInt( void ) const;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& Fixed);