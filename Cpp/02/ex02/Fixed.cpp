#include "Fixed.hpp"

Fixed::Fixed():_rawbits(0)
{
	//std::cout << "Default Constructor called.." << std::endl;
}

Fixed::Fixed(const int raw):_rawbits(raw << _fractional_bits)
{
	//std::cout<< "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw):_rawbits(roundf(raw * (1 << _fractional_bits)))
{
	//std::cout<< "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called.." << std::endl;
}

Fixed::Fixed(Fixed const &Fixed)
{
	//std::cout << "Copy constructor called.." << std::endl;
	this->_rawbits = Fixed.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &Fixed)
{
	//std::cout << "Copy assignment operator called.." << std::endl;
	this->_rawbits = Fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawbits);
}

void		Fixed::setRawBits(const int raw)
{
	this->_rawbits = raw;
}

float		Fixed::toFloat( void ) const
{
	return ((float)this->_rawbits / (1 << this->_fractional_bits));
}

int			Fixed::toInt( void ) const
{
	return (this->_rawbits >> this->_fractional_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& Fixed)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	os << Fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed &f) const
{
	return (this->_rawbits > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->_rawbits < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->_rawbits >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->_rawbits <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->_rawbits == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->_rawbits != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->_rawbits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--()
{
	this->_rawbits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}
