#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private:

		std::string	name;
		int 		hitPoints;
		int 		energyPoints;
		int 		attackDamage;

	public:

		/*				Functions				*/

		void		attack			(const std::string &);
		void		takeDamage		( unsigned int );
		void		beRepaired		( unsigned int );

		/*			Orthodox Canonical Form			*/

					ClapTrap		();
					ClapTrap		(const std::string &);
					ClapTrap		(const ClapTrap &);
					~ClapTrap		();

		ClapTrap	&operator=		(const ClapTrap &);

		/*			Setter && Getter			*/

		void		setName			(const std::string &);
		std::string	getName			();
		void		setHitPoints	( int );
		int			getHitPoints	();
		void		setAttackDamage	( int );
		int			getAttackDamage	();
		void		setEnergyPoint	( int );
		int			getEnergyPoint	();

};

std::ostream		&operator<<		(std::ostream &, ClapTrap &);

#endif