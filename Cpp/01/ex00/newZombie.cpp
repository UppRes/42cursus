#include "Zombie.hpp"

Zombie* newZombie( std::string Name )
{
    Zombie *a;

    a = new Zombie(Name);
    return (a);
}