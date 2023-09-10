#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        double x = std::strtod(av[1], NULL);
        float numf;
        numf = static_cast<float>(x);
        std::cout << "float : ";
        if (numf >= std::numeric_limits<float>::min() && numf <= std::numeric_limits<float>::max())
        {
            std::cout << numf;
            if (numf - static_cast<int>(x) == static_cast<float>(0))
                std::cout << ".0";
            std::cout << "f" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
        //ScalarConverter::convert(av[1]);
    }

    return (0);
}