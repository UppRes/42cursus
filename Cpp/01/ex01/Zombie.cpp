#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << Name << " was dead..." << std::endl;
}

void Zombie::setName(std::string Name)
{
    this->Name = Name;
}

void    Zombie::announce( void )
{
    std::cout << Name << "\t: BraiiiiiiinnnzzzZ..." << std::endl;
}