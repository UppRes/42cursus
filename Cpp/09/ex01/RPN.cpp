#include "RPN.hpp"

std::string					RPN::_input;
std::string					RPN::_allowedChars = "0123456789 +-/*";
std::string					RPN::_allowedOperators = "+-/*";
std::stack<int>				RPN::_arr;

void	RPN::checkArg( int argc, char **argv )
{
	if(argc != 2)
		throw NotEnoughtInputs();
	_input = argv[1];
	RPN::checkvalue();
}

void	RPN::setContesetContainer(void)
{
	size_t i=0;
	while (_input.length() != i)
	{
		if(_input[i] != ' ' && _input[i] >= '0' && _input[i]<='9')
			_arr.push(_input[i] - '0');
		else if( _input[i] != ' ' && _allowedOperators.find(_input[i]) != std::string::npos)
		{
			if (_arr.size() < 2)
				throw (NotEnoughtInputs());
			if (_input[i] == '+')
			{
				int a = _arr.top();
				_arr.pop();
				int b = _arr.top();
				_arr.pop();
				_arr.push(a + b);
			}
			else if (_input[i] == '-')
			{
				int a = _arr.top();
				_arr.pop();
				int b = _arr.top();
				_arr.pop();
				_arr.push(b - a);
			}
			else if (_input[i] == '*')
			{
				int a = _arr.top();
				_arr.pop();
				int b = _arr.top();
				_arr.pop();
				_arr.push(a * b);
			}
			else if (_input[i] == '/')
			{
				int a = _arr.top();
				_arr.pop();
				int b = _arr.top();
				_arr.pop();
				_arr.push(b / a);
			}
		}
		i++;
	}
}

void	RPN::checkvalue(void)
{
	size_t i = 0;
	while (i != _input.length())
	{
		if (_allowedChars.find(_input[i]) == std::string::npos)
			throw (ContainsUnwantedChars());
		else if ((_input[i] >= 48 && _input[i] <= 57) && (_input[i + 1] >= 48 && _input[i + 1] <= 57) )
			throw (WrongInputs());
		i++;
	}
}

void	RPN::printRPN( void )
{
	RPN::setContesetContainer();
	if (_arr.size() == 1)
		std::cout << _arr.top() << std::endl;
	else
		std::cout << "Error : too many arguments" << std::endl;
}
