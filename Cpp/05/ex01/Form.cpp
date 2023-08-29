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

void Form::beSigned(Bureaucrat &bureau)
{
	if (is_signed == true)
	{
		std::cout << form_name << " is already signed." << std::endl;
		throw (Form::FormSignedException());
	}
	else if(bureau.getGrade() > this->getminGrade())
	{
		std::cout << bureau.getName() << " couldn't sign " << form_name << " because grade isn't enough." << std::endl;
		throw(Form::GradeTooLowException());
	}
}

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return ("Exception: Grade too high!");
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return ("Exception: Grade is too low!");
}

const char	*Form::FormSignedException::what( void ) const throw()
{
	return ("Exception: Form is already signed!");
}

				/*			Orthodox Canonical Form			*/

Form::Form(const std::string &name, int min_grade, int exec_grade):form_name(name), min_grade(min_grade), exec_grade(exec_grade)
{
	is_signed = false;
}

Form::Form():form_name("Undefined"), min_grade(150), exec_grade(150)
{
	is_signed = false;
}

Form::Form(const std::string &name):form_name(name), min_grade(150), exec_grade(150)
{
	is_signed = false;
}

Form::Form(const Form &other):form_name(other.form_name), is_signed(other.is_signed), min_grade(other.min_grade), exec_grade(other.exec_grade)
{}

Form::~Form()
{
	is_signed = false;
}

Form	&Form::operator=(const Form &form)
{
	form_name = form.getName();
	is_signed = form.getIsSigned();
	min_grade = form.getminGrade();
	exec_grade = form.getexecuteGrade();

	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
	os << "Form: " << form.getName() << std::endl << "Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< std::endl << "Grade Required to Sign: " << form.getminGrade()
		<< std::endl << "Grade Required to Execute: " << form.getexecuteGrade();
    return (os);
}