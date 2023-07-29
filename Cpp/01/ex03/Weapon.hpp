#pragma once

#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon( void );
        Weapon(std::string type);
        void    setType(std::string type);
        const   std::string getType( void );
};