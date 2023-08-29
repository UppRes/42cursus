#include "ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::action()
{
	std::fstream	fileout;

	fileout.open((getTargetName() + "_shrubbery").c_str(), std::ios::out);

	fileout
<<"        __ _.--..--._ _"<< std::endl
<<"     .-' _/   _/\\_   \\_'-."<< std::endl
<<"    |__ /   _/\\__/\\_   \\__|"<< std::endl
<<"       |___/\\_\\__/  \\___|"<< std::endl
<<"              \\__/"<< std::endl
<<"              \\__/"<< std::endl
<<"               \\__/"<< std::endl
<<"                \\__/"<< std::endl
<<"             ____\\__/___"<< std::endl
<<"       . - '             ' -."<< std::endl
<<"      /                      \\"<< std::endl
<<"~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~  ~~~~~"<< std::endl
<<"  ~~~   ~~~~~   ~!~~   ~~ ~  ~ ~ ~pjb"<< std::endl;
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
