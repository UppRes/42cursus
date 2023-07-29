#include "HumanB.hpp"

HumanB::HumanB( void )
{}

HumanB::HumanB( std::string Name )
{
    this->Name = Name;
}

void HumanB::setWeapon(Weapon& Gun)
{
    this->Gun = &Gun;
}

void HumanB::attack()
{
    std::cout << this->Name
        << " attacs with their "
        << this->Gun->getType() << "."
        << std::endl;
}