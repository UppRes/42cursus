#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << "Cat String constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat const &a) : Animal(a)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = a;
}

Cat &Cat::operator=(Cat const &a)
{
	std::cout << "Cat assignation operator called" << std::endl;
	this->_name = a._name;
	this->_type = a._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miyav ayol" << std::endl;
}
