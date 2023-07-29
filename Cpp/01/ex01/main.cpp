#include "Zombie.hpp"

int main()
{
    Zombie *test;

    test = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++)
        test[i].announce();
    delete[] test;
}