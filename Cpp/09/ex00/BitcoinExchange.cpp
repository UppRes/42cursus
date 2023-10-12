#include "BitcoinExchange.hpp"

std::string						Bitcoin::_input = "";
std::map<std::string, double>	Bitcoin::_data;

void	Bitcoin::checkArg(int index, char **str)
{
	if(index != 2)
		throw Bitcoin::NotEnoughtInputs();
	Bitcoin::checkFile(str[1]);
}

void Bitcoin::error_w(std::string str, std::string str2)
{
	if(str2 != "NULL")
		std::cerr << str << str2 << std::endl;
	else
		std::cerr << str << std::endl;
}

bool Bitcoin::DateCheck(std::string date)
{
	std::string date_day;
	std::string date_month;
	std::string date_year;
	size_t pos1;
	size_t pos2;

	if (!date[0])
	{
		error_w("Error: Date is empty", "NULL");
		return (false);
	}
	pos1 = date.find("-");
    date_year = date.substr(0, pos1);
    pos2 = date.find("-", pos1 + 1);
    date_month = date.substr(pos1 + 1, pos2 - pos1 - 1);
    date_day = date.substr(pos2 + 1);
	if(date_year.length() == 4 || date_month.length() == 2 || date_day.length() == 2)
	{
		if(std::atoi(date_year.c_str()) <= 2008)
			error_w("Error: bad input => ", date);
		else if(std::atoi(date_month.c_str()) > 12 || std::atoi(date_month.c_str()) < 1)
			error_w("Error: bad input => *", date);
		else if(std::atoi(date_day.c_str()) > 31 || std::atoi(date_day.c_str()) < 1 )
			error_w("Error: bad input => ", date);
		else if(std::atoi(date_year.c_str()) == 2009 && std::atoi(date_month.c_str()) == 1 && std::atoi(date_day.c_str()) == 1)
			error_w("Error: bad input => ", date);
		else if(std::atoi(date_year.c_str()) == 2022)
		{
			if(std::atoi(date_month.c_str()) == 3)
			{
				if(std::atoi(date_day.c_str()) > 29)
					error_w("Error: bad input => ", date);
			}
			else if(std::atoi(date_month.c_str()) > 3)
				error_w("Error: bad input => ", date);
		}
		else if(std::atoi(date_year.c_str()) > 2022)
			error_w("Error: bad input => ", date);
		else
			return (true);
		return (false);
	}
	else
		return (false);

}

void Bitcoin::checkFile(std::string variable)
{
	std::ifstream read;
	std::string date;
	std::string value;

	Bitcoin::setContainer_data();

	read.open(variable.c_str());
	if(!read.is_open())
	{
		throw(FileDoesNotExist());
	}
	_input = variable;
	getline(read, variable);
	if(variable.compare("date | value"))
	{
		error_w("Error: at the beginning of the file should be 'date | value'", "NULL");
		return ;
	}
	while (getline(read, variable))
	{
		value.clear();
		date.clear();
        std::istringstream  ss(variable);
        if (std::getline(ss, date, '|') && ss >> value)
		{
            date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
            date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
            value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
            value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
		}
		if(Bitcoin::DateCheck(date) == false)
			continue;
		if (!value[0])
		{
			error_w("Error: Value is empty", "NULL");
			continue;
		}
		if(!value.compare("|"))
		{
			error_w("Error: Input File Entered Values Are Incorrect.", "NULL");
			continue;
		}
		if(std::strtod(value.c_str(), NULL) < 0)
		{
			error_w("Error: not a positive number.", "NULL");
			continue;
		}
		if(std::strtod(value.c_str(), NULL) > 1000)
		{
			error_w("Error: too large a number.", "NULL");
			continue;
		}
		std::cout << date << " => " << value << " = "<< std::ends;
		std::cout << Bitcoin::setContainer_calculate(date) * std::strtod(value.c_str(), NULL) << std::endl;
	}
	read.close();
}

void Bitcoin::setContainer_data(void)
{
	std::ifstream file("data.csv");
	if(!file)
		throw(EnteredValuesAreIncorrect());
	std::string line;
	std::string date;
	std::string tmp_btc_value;
	double btc_value;
	size_t delimiterPos;

	getline(file,line);
	while(getline(file, line))
	{
		delimiterPos = line.find(",");
		if(delimiterPos == std::string::npos)
			throw(EnteredValuesAreIncorrect());
		date = line.substr(0,delimiterPos);
		tmp_btc_value = line.substr(delimiterPos+1, line.length());
		btc_value = std::strtod(tmp_btc_value.c_str(), NULL);
		_data[date] = btc_value;
	}
	file.close();
}

double Bitcoin::setContainer_calculate(std::string date)
{
	std::map<std::string, double>::iterator m = _data.upper_bound(date);

	if (m != _data.begin())
		return((--m)->second);
	return (0);
}
