#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat t0("a0", 0);
	Bureaucrat t1("a1", 1);
	Bureaucrat t2("a2", 151);
	Bureaucrat t3("a3", -25);

	t0.decrement();
	std::cout << t0 << std::endl;
	t0.decrement();
	std::cout << t0 << std::endl;
	t0.increment();
	t0.increment();
	std::cout << t0 << std::endl;
	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;
	std::cout << t3 << std::endl;

	return (0);
}