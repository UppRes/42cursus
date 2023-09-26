#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);

	if (it == container.end())
		throw std::runtime_error("couldn't find :<");
	return it;
}