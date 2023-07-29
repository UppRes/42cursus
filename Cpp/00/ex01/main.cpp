#include "PhoneBook.hpp"

int main()
{
    PhoneBook	myPhone;
    std::string	choice;

	while (1)
	{
		std::cout << "o------o---------o-------o" << std::endl;
		std::cout << "|1(ADD)|2(SEARCH)|3(EXIT)|" << std::endl;
		std::cout << "o------o---------o-------o" << std::endl;
		std::getline(std::cin, choice);
		if (choice.empty())
			std::cerr << "Just usable commands :" << std::endl;
		else if (choice == "1" || choice == "ADD" || choice == "add")
		{
			if (myPhone.add() == -1)
				std::cerr << "Make sure all the information is entered correctly. The person could not be saved." << std::endl;
		}
		else if (choice == "2" || choice == "SEARCH" || choice == "search")
		{
			if (myPhone.search() == -1)
				std::cerr << "Make sure all the information is entered correctly." << std::endl;
		}
		else if (choice == "3" || choice == "EXIT" || choice == "exit")
			break ;
		else
			std::cerr << "Just usable commands :" << std::endl;
	}
	return (0);
}