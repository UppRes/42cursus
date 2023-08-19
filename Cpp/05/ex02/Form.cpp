#include "Form.hpp"

void Form::setName(const std::string &name)
{
	this->form_name = name;
}

std::string Form::getName() const
{
	return (this->form_name);
}

void Form::setminGrade(int signgrade)
{
	this->min_grade = signgrade;
}

int Form::getminGrade() const
{
	return (this->min_grade);
}

void Form::setexecuteGrade(int execgrade)
{
	this->exec_grade = execgrade;
}

int Form::getexecuteGrade() const
{
	return (this->exec_grade);
}

void Form::setSigned()
{
	is_signed = true;
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

bool Form::beSigned(Bureaucrat &bureau)
{
	if (is_signed == true)
	{
		std::cout << form_name << " is already signed." << std::endl;
		return false;
	}
	else if(bureau.getGrade() > this->getminGrade())
	{
		std::cout << bureau.getName() << " couldn't sign " << form_name << " because grade isn't enough." << std::endl;
		throw(Form::GradeTooLowException());
	}
	else
		return true;
}

				/*			Orthodox Canonical Form			*/

Form::Form(const std::string &name, int min_grade, int exec_grade):form_name(name), min_grade(min_grade), exec_grade(exec_grade)
{}

Form::Form()
{
	this->is_signed = false;
}

Form::Form(const std::string &name)
{
	this->form_name		= name;
	this->is_signed		= false;
	this->min_grade		= 150;
	this->exec_grade	= 150;
}

Form::Form(const Form &)
{}

Form::~Form()
{
	this->is_signed = false;
}

Form	&Form::operator=(const Form &)
{
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
	os << "Form: " << form.getName() << std::endl << "Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< std::endl << "Grade Required to Sign: " << form.getminGrade()
		<< std::endl << "Grade Required to Execute: " << form.getexecuteGrade();
    return (os);
}