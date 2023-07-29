#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->total = 0;
}

int	PhoneBook::add()
{
	std::string info[5];

	std::cout << "Name\t\t: ";
	std::getline(std::cin, info[0]);
	if (info[0].empty())
		return (-1);
	std::cout << "SurName\t\t: ";
	std::getline(std::cin, info[1]);
	if (info[1].empty())
		return (-1);
	std::cout << "UserName\t: ";
	std::getline(std::cin, info[2]);
	if (info[2].empty())
		return (-1);
	std::cout << "PhoneNumber\t: ";
	std::getline(std::cin, info[3]);
	if (info[3].empty())
		return (-1);
	std::cout << "DarkSecret\t: ";
	std::getline(std::cin, info[4]);
	if (info[4].empty())
		return (-1);
	this->Person[this->index].setType("Name", info[0]);
	this->Person[this->index].setType("SurName", info[1]);
	this->Person[this->index].setType("UserName", info[2]);
	this->Person[this->index].setType("PhoneNumber", info[3]);
	this->Person[this->index].setType("DarkSecret", info[4]);
	this->index = (this->index + 1) % 8;
	if (this->total < 8)
		this->total++;
	return (0);
}

int	PhoneBook::search()
{
	int	num;
	int	index;

	system("clear");
	index = 0;
	std::cout << "o------o----------o----------o----------o" << std::endl;
	std::cout << "| Index|      Name|   SurName|  UserName|" << std::endl;
	std::cout << "o------o----------o----------o----------o" << std::endl;
	while (index < this->total)
	{
		std::cout << "|     " << index << "|";
		if (this->Person[index].getType("Name").length() > 10)
			std::cout << std::right << std::setw(10) << this->Person[index].getType("Name").substr(0, 9) + "." << "|";
		else
			std::cout << std::right << std::setw(10) << this->Person[index].getType("Name") << "|";
		if (this->Person[index].getType("SurName").length() > 10)
			std::cout << std::right << std::setw(10) << this->Person[index].getType("SurName").substr(0, 9) + "." << "|";
		else
			std::cout << std::right << std::setw(10) << this->Person[index].getType("SurName") << "|";
		if (this->Person[index].getType("UserName").length() > 10)
			std::cout << std::right << std::setw(10) << this->Person[index].getType("UserName").substr(0, 9) + "." << "|";
		else
			std::cout << std::right << std::setw(10) << this->Person[index].getType("UserName") << "|";
		std::cout << std::endl;
		index++;
	}
	std::cout << "o------o----------o----------o----------o" << std::endl;
	std::cout << "Please select the index to display the details." << std::endl;
	std::cin >> num;
	if (num >= 0 && num < total)
	{
		std::cout << "Name\t\t: " << this->Person[num].getType("Name") << std::endl;
		std::cout << "SurName\t\t: " << this->Person[num].getType("SurName") << std::endl;
		std::cout << "UserName\t: "<< this->Person[num].getType("UserName") << std::endl;
		std::cout << "PhoneNumber\t: "<< this->Person[num].getType("PhoneNumber") << std::endl;
		std::cout << "DarkSecret\t: "<< this->Person[num].getType("DarkSecret") << std::endl;
	}
	else
	{
		index = 0;
		while (index < total)
		{
			std::cout << "Name\t\t: " << this->Person[num].getType("Name") << std::endl;
			std::cout << "SurName\t\t: " << this->Person[num].getType("SurName") << std::endl;
			std::cout << "UserName\t: "<< this->Person[num].getType("UserName") << std::endl;
			std::cout << "PhoneNumber\t: "<< this->Person[num].getType("PhoneNumber") << std::endl;
			std::cout << "DarkSecret\t: "<< this->Person[num].getType("DarkSecret") << std::endl;
			index++;
		}
		return (-1);
	}
	return (0);
}