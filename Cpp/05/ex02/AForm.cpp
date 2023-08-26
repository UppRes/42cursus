#include "AForm.hpp"

void AForm::setName(const std::string &name)
{
	this->form_name = name;
}

std::string AForm::getName() const
{
	return (this->form_name);
}

void AForm::setTargetName(const std::string &target_name)
{
	this->target_name = target_name;
}

std::string AForm::getTargetName() const
{
	return (this->target_name);
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

void AForm::execute(Bureaucrat &bureau)
{
	if (is_signed == false)
		throw (AForm::FormNotSignedException());
	else if(bureau.getGrade() > getexecuteGrade())
	{
		std::cout << bureau.getName() << " couldn't execute " << form_name << " because grade isn't enough." << std::endl;
		throw (AForm::GradeTooLowException());
	}
}

void AForm::beSigned(Bureaucrat &bureau)
{
	if (is_signed == true)
		std::cout << form_name << " is already signed." << std::endl;
	else if(bureau.getGrade() > this->getminGrade())
	{
		std::cout << bureau.getName() << " couldn't sign " << form_name << " because grade isn't enough." << std::endl;
		throw(AForm::GradeTooLowException());
	}
}

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Exception: Grade too high!");
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Exception: Grade is too low!");
}

const char	*AForm::FormNotSignedException::what( void ) const throw()
{
	return ("Exception: Form is not signed!");
}

				/*			Orthodox Canonical Form			*/

AForm::AForm(const std::string &name, const std::string &target_name, int min_grade, int exec_grade):form_name(name), target_name(target_name), min_grade(min_grade), exec_grade(exec_grade)
{
	is_signed = false;
}

AForm::AForm():form_name("Undefined"), target_name("Undefined"), min_grade(150), exec_grade(150)
{
	is_signed = false;
}

AForm::AForm(const std::string &name):form_name(name), target_name("Undefined"), min_grade(150), exec_grade(150)
{
	is_signed = false;
}

AForm::AForm(const AForm &other):form_name(other.form_name), target_name(other.target_name), is_signed(other.is_signed), min_grade(other.min_grade), exec_grade(other.exec_grade)
{}

AForm::~AForm()
{
	is_signed = false;
}

AForm	&AForm::operator=(const AForm &form)
{
	form_name = form.getName();
	target_name = form.getTargetName();
	is_signed = form.getIsSigned();
	min_grade = form.getminGrade();
	exec_grade = form.getexecuteGrade();

	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& form) 
{
	os << "Form Name: " << form.getName() << std::endl
	<< "Target Name: " << form.getTargetName() << std::endl
	<< "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl
	<< "Grade Required to Sign: " << form.getminGrade() << std::endl
	<< "Grade Required to Execute: " << form.getexecuteGrade();
    return (os);
}