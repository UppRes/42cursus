#pragma once

#include <iostream>

class Zombie
{
    private:
        std::string Name;
    public:
        Zombie(std::string Name);
        ~Zombie( void );
        void announce( void );
};

Zombie* newZombie(std::string Name);
void    randomChump(std::string Name);
