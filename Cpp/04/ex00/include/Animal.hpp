#pragma once

#include <string>

class Animal
{
public:
	Animal();
	~Animal();
	Animal(std::string);
	Animal(Animal const &);
	Animal &operator=(Animal const &);

	virtual void makeSound() const;
	std::string getname() const;
	void setname(std::string);

	std::string getType() const;
	void setType(std::string);

protected:
	std::string _type;
private:
	std::string _name;
};
