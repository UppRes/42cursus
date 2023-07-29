#include "harlFilter.hpp"

int	main(int ac, char **av)
{
	Harl test;

	switch (ac)
	{
		case 1:
			test.complain("empty");
			break;
		case 2:	
			test.complain(av[1]);
			break;
		default:
			break;
	}
	return (0);
}