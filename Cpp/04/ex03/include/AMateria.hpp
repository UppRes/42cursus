#pragma once

#include <string>
#include "Character.hpp"

class AMateria{
public:
	AMateria(std::string const &);
	AMateria(AMateria const &);
	AMateria &operator=(AMateria const &);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
protected:
	std::string _type;
};
