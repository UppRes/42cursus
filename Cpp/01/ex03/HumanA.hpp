#pragma once 

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string Name;
        Weapon *Gun;
    public:
        HumanA(std::string Name, Weapon& Gun);
        void attack();

};