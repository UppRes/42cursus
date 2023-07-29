#pragma once

#include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &);
		Brain &operator=(const Brain &);

		std::string getIdea(int) const;
		void setIdea(int, std::string);
	private:
		std::string _ideas[100];
};
