#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat				b1("Yufus", 5);
	ShrubberyCreationForm	f1("Palm_tree");
	RobotomyRequestForm		f2("Rico");
	PresidentialPardonForm	f3("Alexander");

	b1.signForm(f1);
	b1.executeForm(f1);

	b1.signForm(f2);
	b1.executeForm(f2);

	b1.signForm(f3);
	b1.executeForm(f3);

	return 0;
}