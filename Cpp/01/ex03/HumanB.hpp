#pragma once 

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string Name;
        Weapon *Gun;
    public:
        HumanB( void );
        HumanB(std::string Name);
        void setWeapon(Weapon& Gun);
        void attack();

};