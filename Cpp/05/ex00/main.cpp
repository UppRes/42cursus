#include "Bureaucrat.hpp"

int main( void )
{
	try
	{

	Bureaucrat t0("Yufus", 1);

	std::cout << t0 << std::endl;
	t0.decrement();
	std::cout << t0 << std::endl;
	t0.increment();
	std::cout << t0 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}