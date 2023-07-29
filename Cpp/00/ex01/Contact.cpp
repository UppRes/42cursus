#include "Contact.hpp"

void	Contact::setType(std::string Type, std::string set)
{
	if (Type.empty() || set.empty())
		return ;
	else if (Type == "Name")		this->Name = set;
	else if (Type == "SurName")		this->SurName = set;
	else if (Type == "UserName")	this->UserName = set;
	else if (Type == "PhoneNumber")		this->PhoneNumber = set;
	else if (Type == "DarkSecret")	this->DarkSecret = set;
}

std::string	Contact::getType(std::string Type)
{
	if (Type.empty())
		return "";
	else if (Type == "Name")		return (this->Name);
	else if (Type == "SurName")		return (this->SurName);
	else if (Type == "UserName")	return (this->UserName);
	else if (Type == "PhoneNumber")		return (this->PhoneNumber);
	else if (Type == "DarkSecret")	return (this->DarkSecret);
	return "";
}
