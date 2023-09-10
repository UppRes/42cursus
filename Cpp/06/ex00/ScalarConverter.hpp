#pragma once

#include <iostream>
#include <limits>

class ScalarConverter
{
    public:

        static void convert(std::string);

        ScalarConverter();
        ScalarConverter(const std::string &);
        ScalarConverter(const ScalarConverter &);
        ~ScalarConverter();

        ScalarConverter &operator=(const ScalarConverter &);
};