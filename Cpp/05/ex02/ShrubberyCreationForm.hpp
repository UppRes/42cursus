#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:

		void action();

		/*			Orthodox Canonical Form			*/

		ShrubberyCreationForm				();
		ShrubberyCreationForm				(const std::string &);
		ShrubberyCreationForm				(const ShrubberyCreationForm &);
		~ShrubberyCreationForm				();

		ShrubberyCreationForm	&operator=	(const ShrubberyCreationForm &);
};
