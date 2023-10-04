#include "MutantStack.hpp"

int main()
{
	MutantStack<int> numbers;
	MutantStack<int> test;

	numbers.push(12);
	numbers.push(6);
	numbers.push(18);
	numbers.push(3);
	test.begin();

	test = numbers;
	MutantStack<int>::iterator it = test.begin();

	it++;
	it--;
	while (*it != *test.end())
		std::cout << *(it++) << std::endl;

	return (0);
}