#pragma once

#include <iostream>

class Zombie
{
private:
    std::string Name;
public:
    ~Zombie();
    void setName(std::string Name);
    void announce( void );
};

Zombie* zombieHorde(int N, std::string Name);
