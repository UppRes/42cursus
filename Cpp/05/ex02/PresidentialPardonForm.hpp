#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		void action();

		/*			Orthodox Canonical Form			*/

		PresidentialPardonForm				();
		PresidentialPardonForm				(const std::string &);
		PresidentialPardonForm				(const PresidentialPardonForm &);
		~PresidentialPardonForm				();

		PresidentialPardonForm		&operator=	(const PresidentialPardonForm &);
};
