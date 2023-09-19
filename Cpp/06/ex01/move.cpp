#include "Serializer.hpp"

struct Data
{
	int		x;
	double	y;
};

Data *move(uintptr_t test)
{
    Data *comp = Serializer::deserialize(test);

    std::cout << "comp->x++ = " << comp->x++ << " , comp->y++ = " << comp->y++ << std::endl;
    return (comp);
}