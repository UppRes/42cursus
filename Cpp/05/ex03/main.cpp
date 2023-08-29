#include "Intern.hpp"

int main()
{
	Bureaucrat	b1("Yufus", 5);
	Intern		test;
	AForm		*f[3] = {test.makeForm("shrubbery creation", "Palm_tree"), test.makeForm("robotomy request", "Rico"), test.makeForm("presidential pardon", "Alexander")};

	b1.signForm(*f[0]);
	b1.executeForm(*f[0]);

	b1.signForm(*f[1]);
	b1.executeForm(*f[1]);

	b1.signForm(*f[2]);
	b1.executeForm(*f[2]);

	return (0);
}