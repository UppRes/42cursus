#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		void action();

		/*			Orthodox Canonical Form			*/

		RobotomyRequestForm				();
		RobotomyRequestForm				(const std::string &);
		RobotomyRequestForm				(const RobotomyRequestForm &);
		~RobotomyRequestForm			();

		RobotomyRequestForm		&operator=	(const RobotomyRequestForm &);
};
