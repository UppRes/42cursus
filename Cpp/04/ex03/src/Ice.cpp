#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {

}

Ice::Ice(Ice const &obj) : AMateria(obj) {
	*this = obj;
}

Ice &Ice::operator=(Ice const &obj) {
	AMateria::operator=(obj);
	return *this;
}

Ice::~Ice() {

}

Ice::AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
