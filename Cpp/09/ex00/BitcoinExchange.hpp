#pragma once

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:

		std::map<std::string, double> data;

	public:

		BitcoinExchange();
		~BitcoinExchange();

};