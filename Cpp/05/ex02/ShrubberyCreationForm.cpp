#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::action()
{
	std::cout << "test" << std::endl;
}

/*			Orthodox Canonical Form			*/

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", "Undefined", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target_name):AForm("ShrubberyCreationForm", target_name, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form):AForm(form)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	AForm::operator=(form);

	return *this;
}
