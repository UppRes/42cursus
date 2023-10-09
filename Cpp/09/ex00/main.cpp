#include "BitcoinExchange.hpp"

int main(int index, char **str)
{
	try
	{
		Bitcoin::checkArg(index, str);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
