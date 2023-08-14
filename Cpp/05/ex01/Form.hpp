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

	    void setName(const std::string &);
    	std::string getName() const;

    	void setminGrade(int signgrade);
    	int getminGrade() const;

    	void setexecuteGrade(int execgrade);
    	int getexecuteGrade() const;

    	bool getIsSigned() const;

    	void beSigned(Bureaucrat &bureaucrat);

		class GradeTooLowException : public std::exception
    	{
    	    public:
    	        const char *what() const throw() { return ("Too Low Exception"); };
    	};

    	class GradeTooHighException : public std::exception
    	{
    	    public:
    	        const char *what() const throw() { return ("Too High Exception"); };
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