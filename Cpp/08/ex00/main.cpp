#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	try
	{
		std::vector<int> container;

		container.push_back(4);
		container.push_back(0);
		container.push_back(2);
		container.push_back(1);
    	std::vector<int>::iterator it = easyfind(container, 3);

		*it = 3;
		it = container.begin();
		while (it != container.end())
			std::cout << *(it++) << std::endl;

		container.clear();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}