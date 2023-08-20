#include "AForm.hpp"

void AForm::setName(const std::string &name)
{
	this->form_name = name;
}

std::string AForm::getName() const
{
	return (this->form_name);
}

void AForm::setminGrade(int signgrade)
{
	this->min_grade = signgrade;
}

int AForm::getminGrade() const
{
	return (this->min_grade);
}

void AForm::setexecuteGrade(int execgrade)
{
	this->exec_grade = execgrade;
}

int AForm::getexecuteGrade() const
{
	return (this->exec_grade);
}

void AForm::setSigned()
{
	is_signed = true;
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

bool AForm::beSigned(Bureaucrat &bureau)
{
	if (is_signed == true)
	{
		std::cout << form_name << " is already signed." << std::endl;
		return false;
	}
	else if(bureau.getGrade() > this->getminGrade())
	{
		std::cout << bureau.getName() << " couldn't sign " << form_name << " because grade isn't enough." << std::endl;
		throw(AForm::GradeTooLowException());
	}
	else
		return true;
}

				/*			Orthodox Canonical Form			*/

AForm::AForm(const std::string &name, int min_grade, int exec_grade):form_name(name), min_grade(min_grade), exec_grade(exec_grade)
{}

AForm::AForm()
{
	this->is_signed = false;
}

AForm::AForm(const std::string &name)
{
	this->form_name		= name;
	this->is_signed		= false;
	this->min_grade		= 150;
	this->exec_grade	= 150;
}

AForm::AForm(const AForm &)
{}

AForm::~AForm()
{
	this->is_signed = false;
}

AForm	&AForm::operator=(const AForm &)
{
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& form) 
{
	os << "AForm: " << form.getName() << std::endl << "Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< std::endl << "Grade Required to Sign: " << form.getminGrade()
		<< std::endl << "Grade Required to Execute: " << form.getexecuteGrade();
    return (os);
}