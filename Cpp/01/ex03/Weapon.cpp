#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

void  Weapon::setType(std::string type)
{
    this->type = type;
}

std::string const Weapon::getType( void )
{
    return (this->type);
}