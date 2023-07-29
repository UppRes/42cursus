#pragma once

#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	~Dog();
	Dog(std::string);
	Dog(Dog const &);
	Dog &operator=(Dog const &);
	void makeSound() const;
private:
	std::string _name;
};
