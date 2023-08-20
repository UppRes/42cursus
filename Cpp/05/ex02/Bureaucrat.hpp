#pragma once

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:

		std::string		name;
		int				grade;

	public:

			void		signForm(AForm &);

			class GradeTooHighException : public std::exception
			{
				public:
					const char *what() const throw() {	return ("Grade is too High ( MAX : 1, MIN : 150 )");	};
			};

			class GradeTooLowException : public std::exception
			{
				public:
					const char *what() const throw() {	return ("Grade is too Low ( MAX : 1, MIN : 150 )");	};
			};

			void		increment();
			void		decrement();

			void		setGrade	(int)		 ;
			int			getGrade	()		const;
			std::string	getName		()		const;

			Bureaucrat		(const std::string &, int);

			/*			Orthodox Canonical Form			*/

					Bureaucrat		();
					Bureaucrat		(const std::string &);
					Bureaucrat		(const Bureaucrat &);
					~Bureaucrat		();

		Bureaucrat	&operator=		(const Bureaucrat &);

};

std::ostream&	operator<<(std::ostream &o, Bureaucrat &b);