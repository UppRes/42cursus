#include "ClapTrap.hpp"

int main()
{
    ClapTrap	p1("Lancelot");
	ClapTrap	p2("Selena");
	int			gethp = 5;

	p1.setAttackDamage(8);
	p2.setAttackDamage(15);

	std::cout << std::endl << p1 << std::endl << p2 << std::endl;

    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttackDamage());

	std::cout << std::endl << p1 << std::endl << p2 << std::endl;

    p2.beRepaired(gethp);

	std::cout << std::endl << p1 << std::endl << p2 << std::endl;

	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttackDamage());
	p1.beRepaired(gethp);

	std::cout << std::endl << p1 << std::endl << p2 << std::endl;

    return (0);
}