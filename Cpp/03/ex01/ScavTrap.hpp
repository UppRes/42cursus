#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		/*				Functions				*/

		void 		guardGate		();

		/*			Orthodox Canonical Form			*/

					ScavTrap		();
					ScavTrap		(const std::string &);
					ScavTrap		(const ScavTrap &);
					~ScavTrap		();

		ScavTrap	&operator=		(const ScavTrap &);

};

std::ostream	&operator<<(std::ostream &stream, ScavTrap &);

#endif