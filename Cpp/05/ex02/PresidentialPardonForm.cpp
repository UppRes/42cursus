#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::action()
{
	std::cout << "test" << std::endl;
}

/*			Orthodox Canonical Form			*/

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", "Undefined", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target_name):AForm("PresidentialPardonForm", target_name, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form):AForm(form)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	AForm::operator=(form);

	return *this;
}
