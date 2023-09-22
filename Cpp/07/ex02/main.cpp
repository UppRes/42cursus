#include "Array.hpp"

int main()
{
    try
    {
        Array<char> a(5);
        int *p = new int();

        std::cout << *p << std::endl;
        a[0] = 'Y';
        a[1] = 'u';
        a[2] = 's';
        a[3] = 'u';
        a[4] = 'f';
        if (a[1] == a[3])
            std::cout << a.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return (0);
}