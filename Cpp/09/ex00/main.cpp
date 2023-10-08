#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "arg error" << std::endl;
        return (1);
    }
    (void)av;

    std::map<std::string, double> btc;

    btc["2011-01-01"] = 2;
    btc["2011-01-03"] = 0.3;
    btc["aa"] = 3;

    std::string date = "2011-01-01";
    // double      value = 3;

    std::map<std::string, double>::iterator it = btc.upper_bound(date);
    if (it != btc.begin())
        std::cout << (--it)->first << std::endl;

    // try
    // {
    //     BitcoinExchange btc;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    return (0);
}