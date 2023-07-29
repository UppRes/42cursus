#pragma once

#include <iostream>

class Fixed
{
	private:
		int					_rawbits;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(Fixed const &Fixed);

		~Fixed();

		Fixed& operator=(Fixed const &Fixed);

		void		setRawBits(const int raw);
		int			getRawBits() const;
};