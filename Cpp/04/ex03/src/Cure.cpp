#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {

}

Cure::Cure(Cure const &obj) : AMateria(obj) {
	*this = obj;
}

Cure &Cure::operator=(Cure const &obj) {
	AMateria::operator=(obj);
	return *this;
}

Cure::~Cure() {

}

Cure::AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
