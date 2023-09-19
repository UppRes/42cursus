#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	srand(time(NULL));
	int number = rand() % 3;
	if (number == 0)
	{
		std::cout << "Generated A" << std::endl;
		return (new A);
	}
	else if (number == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B);
	}
	std::cout << "Generated C" << std::endl;
	return (new C);
}

void	identify( Base *p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown type: *" << std::endl;
}

void	identify( Base &p )
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "A&" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "B&" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "C&" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main( void )
{
	Base *ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;
    return (0);
}