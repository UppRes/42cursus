#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:

		std::string		form_name;
		bool			is_signed;
		int				min_grade;
		int				exec_grade;

	public:

    	void beSigned(Bureaucrat &bureau);

	    void setName(const std::string &);
    	std::string getName() const;

    	void setminGrade(int signgrade);
    	int getminGrade() const;

    	void setexecuteGrade(int execgrade);
    	int getexecuteGrade() const;

		void setSigned();
    	bool getIsSigned() const;

		class GradeTooLowException : public std::exception
    	{
    	    public:
    	        const char *what() const throw();
    	};

    	class GradeTooHighException : public std::exception
    	{
    	    public:
    	        const char *what() const throw();
    	};

		class FormSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

				Form		(const std::string &, int, int);

		/*			Orthodox Canonical Form			*/

				Form		();
				Form		(const std::string &);
				Form		(const Form &);
				~Form		();

		Form	&operator=		(const Form &);
};

std::ostream &operator<<(std::ostream &o, const Form &src);