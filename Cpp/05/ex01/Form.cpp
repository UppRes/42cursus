#include "Form.hpp"

const std::string Form::Get()
{
	return (this->form_name);
}

				/*			Orthodox Canonical Form			*/
Form::Form()
{}

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
{}

Form	&Form::operator=(const Form &)
{
	return (*this);
}
