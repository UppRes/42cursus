#pragma once

# include <iostream>
# include <map>
# include <fstream>

class Bitcoin
{
	private:
		static std::string						_input;
		static std::map<std::string, double>	_data;

	public:
		static void			checkArg( int index, char **str );
		static void			checkFile( std::string variable);
		static void			setContainer_data(void);
		static bool			DateCheck(std::string date);
		static void 		error_w(std::string str, std::string str2);
		static double		setContainer_calculate(std::string date);

		class NotEnoughtInputs : public std::exception
		{
			public:
				const char *what(void) const throw() {return ("###	Error: not enought inputs!	###");}
		};

		class TooLargeNumber : public std::exception
		{
			public:
				const char *what(void) const throw() {return ("Error: could not open file.");}
		};

		class FileDoesNotExist : public std::exception
		{
			public:
				const char *what(void) const throw() {return ("###	Error: file doesn't exist!	###");}
		};

		class EnteredValuesAreIncorrect : public std::exception
		{
			public:
				const char *what(void) const throw() {return ("Error: Input File Entered Values Are Incorrect.");}
		};

		class EnteredValuesAreIncorrectData : public std::exception
		{
			public:
				const char *what(void) const throw() {return ("Error: Date File Entered Values Are Incorrect.");}
		};
};
