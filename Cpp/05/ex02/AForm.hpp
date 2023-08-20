#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	private:

		std::string		form_name;
		bool			is_signed;
		int				min_grade;
		int				exec_grade;

	public:

    	bool beSigned(Bureaucrat &bureau);

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
    	        const char *what() const throw() { return ("grade is too low."); };
    	};

    	class GradeTooHighException : public std::exception
    	{
    	    public:
    	        const char *what() const throw() { return ("grade is too high."); };
    	};

				AForm		(const std::string &, int, int);

		/*			Orthodox Canonical Form			*/

				AForm		();
				AForm		(const std::string &);
				AForm		(const AForm &);
				~AForm		();

		AForm	&operator=		(const AForm &);
};

std::ostream &operator<<(std::ostream &o, const AForm &src);