#pragma once

#include <iostream>

template <typename T>
class Array 
{
	private:
	    T				*data;
	    unsigned int	length;

	public:
	    Array() : data(NULL), length(0) {}

	    Array(unsigned int n) : length(n) {
	        data = new T[length];
	        for (unsigned int i = 0; i < length; ++i) {
	            data[i] = T();
	        }
	    }

	    Array(const Array<T>& other) : length(other.size) {
	        data = new T[length];
	        for (unsigned int i = 0; i < length; ++i) {
	            data[i] = other.data[i];
	        }
	    }

	    Array<T>& operator=(const Array<T>& other) {
	        if (this != &other) {
	            delete[] data;
	            length = other.length;
	            data = new T[length];
	            for (unsigned int i = 0; i < length; ++i) {
	                data[i] = other.data[i];
	            }
	        }
	        return *this;
	    }

	    ~Array() {
	        delete[] data;
	    }

	    T& operator[](unsigned int index) {
	        if (index >= length) {
	            throw std::out_of_range("Index out of range");
	        }
	        return data[index];
	    }

	    unsigned int size() const {
	        return length;
	    }
};