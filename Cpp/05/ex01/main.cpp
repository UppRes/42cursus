#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	bureaucrat("Yufus", 1);
	Form		form("istsozlesmesi", 2, 5);

	form.beSigned(bureaucrat);

	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
}