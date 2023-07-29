#include "Zombie.hpp"

int main()
{
    Zombie a("Yusuf");
    Zombie *b;

    a.announce();
    b = newZombie("Heap");
    b->announce();
    randomChump("Stack");
    delete b;
}