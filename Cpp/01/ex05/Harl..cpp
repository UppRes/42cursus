#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "This is [ DEBUG ] message.." << std::endl;
}

void	Harl::info( void )
{
	std::cout << "This is [ INFO ] message.." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "This is [ WARNING ] message.." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is [ ERROR ] message.." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	av[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;
	void		(Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = 0;
	while (i < 4)
	{
		switch (strcmp(level.c_str(), av[i].c_str()))
		{
		case 0:
			(this->*func[i])();
			return ;
		default:
			break;
		}
		i++;
	}
	std::cerr << "[ ERROR ]\n" << "Just use: \"DEBUG\", \"INFO\", \"WARNING\" or \"ERROR\"" << std::endl;
}
