#pragma once

#include <iostream>

class Form
{
	private:

		std::string		form_name;
		bool			is_signed;
		int				min_grade;
		int				exec_grade;

	public:

		const std::string Get();

		/*			Orthodox Canonical Form			*/

				Form		();
				Form		(const std::string &);
				Form		(const Form &);
				~Form		();

		Form	&operator=		(const Form &);
};