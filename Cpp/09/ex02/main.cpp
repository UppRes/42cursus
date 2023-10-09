#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		argc--;
		argv++;
		PmergeMe::checkArg(argc, argv);
		PmergeMe::setContainers(argc, argv);
		PmergeMe::sortListContainer();
		PmergeMe::sortVectorContainer();
	}
	catch ( std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
