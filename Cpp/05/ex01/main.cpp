#include "Form.hpp"

int	main()
{
	Bureaucrat	bureau("Yufus", 2);
	Form		form("istsozlesmesi", 1, 5);

	form.beSigned(bureau);

	std::cout << bureau << std::endl;
	std::cout << form << std::endl;
}