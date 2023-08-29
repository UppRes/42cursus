#include "Intern.hpp"

AForm*	Intern::newShrubbery(const std::string &target )
{
	return(new ShrubberyCreationForm(target));
}

AForm*	Intern::newPresidential(const std::string &target )
{
	return(new PresidentialPardonForm(target));
}

AForm*	Intern::newRobotomy(const std::string &target )
{
	return(new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm(const std::string &form_name, const std::string &target_name)
{
	std::string create[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*	(Intern::*t[3])(const std::string &) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
	int i;

	i = -1;
	while (++i < 3)
	{
		if(!create[i].compare(form_name))
			return (this->*t[i])(target_name);
	}
	return NULL;
}

/*			Orthodox Canonical Form			*/

Intern::Intern()
{}

Intern::Intern(const std::string &form)
{
	(void)form;
}

Intern::Intern(const Intern &intern)
{
	(void)intern;
}

Intern::~Intern()
{}

Intern		&Intern::operator=	(const Intern &intern)
{
	(void)intern;
	return *this;
}