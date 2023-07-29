#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon& Gun)
{
    this->Name = Name;
    this->Gun = &Gun;
}

void HumanA::attack()
{
    std::cout << this->Name
        << " attacs with their "
        << this->Gun->getType() << "."
        << std::endl;
}
