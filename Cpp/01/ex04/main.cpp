#include "include.hpp"

int main(int ac, char **av)
{
	std::ifstream			ifile;
	std::ofstream			ofile;
    std::string				str;
	std::string				av1;
	std::string				av2;
	std::string::size_type	pos;

	if (ac != 4)
  	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	ifile.open(av[1]);
	if (!ifile.is_open())
	{
		std::cerr << "Error: Failed to open input file '" << av[1] << "'" << std::endl;
		return (1);
	}

	ofile.open(((std::string)av[1] + ".replace").c_str());
	if (!ofile.is_open())
	{
		std::cerr << "Error: Failed to open output file '" << av[1] << "'" << ".replace" << std::endl;
		return (1);
	}

	av1 = av[2];
	av2 = av[3];
	pos = 0;

	while (std::getline(ifile, str))
	{
		pos = str.find(av1);
		while (pos != std::string::npos)
        {
			str = str.substr(0, pos) + av2 + str.substr(pos + av1.size(), str.size());
			pos = str.find(av1);
		}
		if (!ifile.eof())
			str += '\n';
		ofile << str;
	}
	ifile.close();
	ofile.close();
	return (0);
}