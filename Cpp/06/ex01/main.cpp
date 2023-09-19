#include "Serializer.hpp"

Data *move(uintptr_t test);

struct Data
{
	int		a;
	double	b;
};

int main()
{
    Data data;

    data.a = 42;
    data.b = 42.42;
    uintptr_t tmp = Serializer::serialize(&data);

    if (&data == move(tmp))
    {
        std::cout << "they have identical address" << std::endl;
        std::cout << "data.a = " << data.a << " , data.b = " << data.b << std::endl;
    }
    else
        std::cout << "they have different address" << std::endl;

    return (0);
}