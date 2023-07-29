#include "Fixed.hpp"

Fixed::Fixed():_rawbits(0)
{
	std::cout << "Constructor called.." << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called.." << std::endl;
}

Fixed::Fixed(Fixed const &Fixed)
{
	std::cout << "Copy constructor called.." << std::endl;
	this->_rawbits = Fixed.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &Fixed)
{
	std::cout << "Copy assignment operator called.." << std::endl;
	this->_rawbits = Fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawbits);
}

void		Fixed::setRawBits(const int raw)
{
	this->_rawbits = raw;
}