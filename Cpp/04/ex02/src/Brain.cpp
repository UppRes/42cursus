#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b._ideas[i];
}

Brain &Brain::operator=(const Brain &b)
{
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b._ideas[i];
	return *this;
}

std::string Brain::getIdea(int i) const
{
	return this->_ideas[i];
}

void Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
}