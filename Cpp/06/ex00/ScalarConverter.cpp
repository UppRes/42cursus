#include "ScalarConverter.hpp"

char convertToChar(int a)
{
	return (static_cast<char>(a));
}

void ScalarConverter::convert(std::string av1)
{
	std::cout << "char: ";
	if (av1.length() == 1 && !std::isdigit(av1[0]))
		std::cout << "\'" << convertToChar(av1[0]) << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
};

ScalarConverter::ScalarConverter()
{};

ScalarConverter::ScalarConverter(const std::string &name)
{
	(void)name;
};

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
};

ScalarConverter::~ScalarConverter()
{};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
};