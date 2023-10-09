#pragma once

# include <iostream>
# include <list>
# include <vector>
# include <sstream>

class PmergeMe{

private:
	static std::list<int>	_list;
	static std::vector<int>	_vector;
	static int				_insertSortingLimit;

public:
	static std::string	intToString( int num );
	static void			checkArg( int argc, char **argv );
	static void			setContainers( int argc, char **argv );
	static double		measureTime( clock_t start, clock_t end );

	/* List methods */

	static void						sortListContainer( void );
	static void						ListMergeInsertSorting( std::list<int>& list );
	static void						ListMergeSorting( std::list<int>& list, std::list<int>& left, std::list<int>& right );
	static void						ListInsertSorting( std::list<int>::iterator begin, std::list<int>::iterator end );
	static std::list<int>::iterator ListGetPrev( std::list<int>::iterator it );
	static std::list<int>::iterator ListGetNext( std::list<int>::iterator it );
	static bool						isListSorted( std::list<int>& list );
	static void						printerList( std::string line );

	/* Vector methods */
	static void						sortVectorContainer( void );
	static void						VectorMergeInsertSorting( std::vector<int>& vector, int left, int right );
	static void						VectorMergeSorting( std::vector<int>& vector, int left, int middle, int right );
	static void						VectorInsertSorting( std::vector<int>& vector, int left, int right );
	static bool						isVectorSorted( std::vector<int>& vector );
	static void						printerVector( std::string line );

	class NotEnoughtInputs : public std::exception{
		public:
			const char *what(void) const throw()
			{
				return ("###	Error: not enought inputs!	###");
			}
	};

	class WrongInputs : public std::exception{
		public:
			const char *what(void) const throw()
			{
				return ("###	Error: wrong inputs!	###");
			}
	};

};
