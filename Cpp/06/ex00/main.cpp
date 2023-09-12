#include "ScalarConverter.hpp"

// #include <iostream>
// #include <sstream>
// #include <limits>
// #include <cstdlib>

// class ScalarConverter {
// public:
//     static void convert(const std::string& str) {
//         int intResult = 0;
//         float floatResult = 0.0f;
//         double doubleResult = 0.0;

//         // Convert to char
//         if (str.length() == 1) {
//             if (isprint(str[0])) {
//                 intResult = static_cast<int>(str[0]);
//             } else {
//                 std::cout << "char: Non displayable" << std::endl;
//             }
//         } else {
//             std::cout << "char: impossible" << std::endl;
//             intResult = atoi(str.c_str());
//             floatResult = strtof(str.c_str(), NULL);
//             doubleResult = strtod(str.c_str(), NULL);
//         }

//         // Convert to int
//         std::cout << "int: " << intResult << std::endl;

//         // Convert to float
//         if (!(floatResult == std::numeric_limits<float>::quiet_NaN()) || !(floatResult == std::numeric_limits<float>::infinity())) {
//             std::cout << "float: " << floatResult << "f" << std::endl;
//         } else {
//             std::cout << "float: impossible" << std::endl;
//         }

//         // Convert to double
//         if (!(doubleResult == std::numeric_limits<double>::quiet_NaN()) || !(doubleResult == std::numeric_limits<double>::infinity())) {
//             std::cout << "double: " << doubleResult << std::endl;
//         } else {
//             std::cout << "double: impossible" << std::endl;
//         }
//     }
// };

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
//         return 1;
//     }

//     std::string input = argv[1];
//     ScalarConverter::convert(input);

//     return 0;
// }

bool    isNanfinity(double num)
{
    return ((num != num) || (num == std::numeric_limits<double>::infinity() || num == -std::numeric_limits<double>::infinity()));
}

int main(int ac, char **av)
{
    if (ac == 2)
    {

    //     double numd = std::strtod(av[1], NULL);

    // float numf = std::atof(av[1]);

    // std::cout << "float : ";
    // if (isNanfinity(numf))
    // {
    //     std::cout << numf;
    //     if (numf - static_cast<int>(numd) == static_cast<float>(0))
    //         std::cout << ".0";
    //     std::cout << "f" << std::endl;
    // }
    // else
    //     std::cout << "impossible" << std::endl;

        ScalarConverter::convert(av[1]);
    }
    // std::cout << sizeof(double) << " : " << std::numeric_limits<double>::min() << " : " << std::numeric_limits<double>::max() << std::endl;
    // std::cout << sizeof(float) << " : " << std::numeric_limits<float>::min() << " : " << std::numeric_limits<float>::max() << std::endl;
    // std::cout << sizeof(size_t) << " : " << std::numeric_limits<size_t>::min() << " : " << std::numeric_limits<size_t>::max() << std::endl;
    // std::cout << sizeof(long) << " : " << std::numeric_limits<long>::min() << " : " << std::numeric_limits<long>::max() << std::endl;
    // std::cout << sizeof(int) << " : " << std::numeric_limits<int>::min() << " : " << std::numeric_limits<int>::max() << std::endl;
    // double  numd = std::strtod(av[1], NULL);
    // float   numf = std::atof(av[1]);
    // int     numi = std::atoi(av[1]);
    // std::cout << numd << '\n' << numf << '\n' << numi << std::endl;
    // if ((numd >= std::numeric_limits<int>::min() && numd <= std::numeric_limits<int>::max()))
    //     std::cout << numi << std::endl;
    // else
    //     std::cout << "impossible" << std::endl;

    return (0);
}