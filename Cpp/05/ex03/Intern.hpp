#pragma once

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{

	public:

		AForm*	makeForm(const std::string &, const std::string &);
		AForm*	newShrubbery(const std::string &);
		AForm*	newPresidential(const std::string &);
		AForm*	newRobotomy(const std::string &);

		/*			Orthodox Canonical Form			*/

		Intern				();
		Intern				(const std::string &);
		Intern				(const Intern &);
		~Intern				();

		Intern		&operator=	(const Intern &);

};