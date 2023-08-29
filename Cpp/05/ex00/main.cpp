#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat t0("Yufus", 1);

	std::cout << t0 << std::endl;
	t0.decrement();
	std::cout << t0 << std::endl;
	t0.increment();
	std::cout << t0 << std::endl;

	return (0);
}