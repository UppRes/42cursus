#pragma once

#include <iostream>

class Contact
{
	private:
    	std::string Name;
    	std::string SurName;
    	std::string UserName;
    	std::string PhoneNumber;
    	std::string DarkSecret;
	public:
		void		setType(std::string Type, std::string Info);
		std::string getType(std::string Type);
};
