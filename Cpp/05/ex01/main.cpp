#include "Form.hpp"

int	main()
{
	try
	{
			
	Bureaucrat	b1("Yufus", 1);
	Bureaucrat	b2("Others", 2);
	Form		form("istsozlesmesi", 1, 5);

	b1.signForm(form);
	b1.signForm(form);
	b2.signForm(form);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}