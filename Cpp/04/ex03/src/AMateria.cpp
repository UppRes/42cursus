#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {

}

AMateria::AMateria(AMateria const &obj) {
	*this = obj;
}

AMateria &AMateria::operator=(AMateria const &obj) {
	_type = obj._type;
	return *this;
}

AMateria::~AMateria() {

}

std::string const &AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	target.getName();
}
