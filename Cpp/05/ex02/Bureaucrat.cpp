#include "Bureaucrat.hpp"
#include "Form.hpp"

void	Bureaucrat::signForm(Form &form)
{
	if (form.beSigned(*this))
	{
		form.setSigned();
		std::cout << name << " signed " << form.getName() << std::endl;
	}
}

void		Bureaucrat::setGrade	(int grade)
{
	if (grade > 150)
		throw	GradeTooLowException();
	else if (grade < 1)
		throw	GradeTooHighException();
	this->grade = grade;
}

void		Bureaucrat::increment()
{
	setGrade(this->grade - 3);
}

void		Bureaucrat::decrement()
{
	setGrade(this->grade + 2);
}

int			Bureaucrat::getGrade	(void) const
{
	return (grade);
}

std::string	Bureaucrat::getName		(void) const
{
	return (name);
}

Bureaucrat::Bureaucrat		(const std::string &name, int grade): name(name)
{
	setGrade(grade);
}

/*				Orthodox Canonical Form					*/

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat		(const std::string &name):name(name)
{}

Bureaucrat::Bureaucrat		(const Bureaucrat &b):name(b.name)
{
	setGrade(grade);
}

Bureaucrat::~Bureaucrat		()
{}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &b)
{
	this->name = b.name;
	this->grade = b.grade;
	return (*this);
}

/*					Stream	Functions				*/

std::ostream	&operator<<(std::ostream &o, Bureaucrat &b){
	o << b.getName() << ", Bureaucrat Grade " << b.getGrade();
	return o;
}