#pragma once

#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	~Cat();
	Cat(std::string);
	Cat(Cat const &);
	Cat &operator=(Cat const &);
	void makeSound() const;

	Brain		*_brain;
private:
	std::string	_name;
};
