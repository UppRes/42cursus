#pragma once

#include "AMateria.hpp"
#include <string>

class IMateriaSource{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(MateriaSource const &);
	MateriaSource &operator=(MateriaSource const &);
	~MateriaSource();

	void		learnMateria(AMateria*);
	AMateria	*createMateria(std::string const & type);
private:
	AMateria	*_learned[4];
};
