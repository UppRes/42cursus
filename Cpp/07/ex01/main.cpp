#include "iter.hpp"

template <typename ValueType>
void printValue(ValueType &value)
{
    std::cout << value;
}

template <typename T>
void doubleValue(T &value)
{
    value *= 2;
}

int main()
{
    std::string a[] = {"10", "0", "300", "32"};
    iter(a, sizeof(a)/sizeof(a[0]), printValue);
    std::cout << std::endl;

    int b[] = {5, 0, 150, 16};
	iter(b, sizeof(b)/sizeof(b[0]), doubleValue);
	iter(b, sizeof(b)/sizeof(b[0]), printValue);
    std::cout << std::endl;

    char c[] = {'1', '\0', 48, 48,'3', '0', '0', '3', '2'};
	iter(c, sizeof(c)/sizeof(c[0]), printValue);
    std::cout << std::endl;

    return (0);
}