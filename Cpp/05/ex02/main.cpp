#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat				b1("Yufus", 151);
	ShrubberyCreationForm	f1("Home");

	std::cout << f1 << std::endl;

	b1.signForm(f1);

	return 0;
}