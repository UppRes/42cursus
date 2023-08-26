#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::action()
{
	std::cout << "test" << std::endl;
}

/*			Orthodox Canonical Form			*/

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", "Undefined", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target_name):AForm("RobotomyRequestForm", target_name, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form):AForm(form)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	AForm::operator=(form);

	return *this;
}
