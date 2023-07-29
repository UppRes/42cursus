#include "Zombie.hpp"

Zombie::Zombie(std::string Name)
{
    this->Name = Name;
}

Zombie::~Zombie()
{
    std::cout << Name << " was dead..." << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << Name << "\t: BraiiiiiiinnnzzzZ..." << std::endl;
}