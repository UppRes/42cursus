#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() {}
    ~MutantStack() {}
    MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {}
    MutantStack<T> &operator=(const MutantStack<T> &copy)
    {
        std::stack<T>::operator=(copy);
        return *this;
    }

    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }
};