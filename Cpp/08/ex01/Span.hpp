#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int N;

    public:
    	Span() {}
        Span(unsigned int N) : N(N) {}
    	Span &operator=(const Span &copy) {
			this->N = copy.N;
			this->numbers = copy.numbers;
			return (*this);
		}
		~Span(){
			numbers.clear();
		}

        void addNumber(int num) {
            if (numbers.size() >= N) {
                throw std::overflow_error("Span is full");
            }
            numbers.push_back(num);
        }

		unsigned int shortestSpan() {
		    if (numbers.size() < 2) {
		        throw std::runtime_error("Not enough numbers to calculate shortest span");
		    }

		    long minSpan = std::numeric_limits<int>::max();
	
		    for (size_t i = 0; i < numbers.size(); ++i)
			{
		        for (size_t j = i + 1; j < numbers.size(); ++j)
				{
		            long span = std::abs(numbers[i] - numbers[j]);
		            if (span < minSpan) {
		                minSpan = span;
		            }
		        }
		    }

		    return minSpan;
		}

        unsigned int longestSpan() {
            if (numbers.size() < 2) {
                throw std::runtime_error("Not enough numbers to calculate longest span");
            }

            long minNum = *std::min_element(numbers.begin(), numbers.end());
            long maxNum = *std::max_element(numbers.begin(), numbers.end());

            return (maxNum - minNum);
        }

	    template <typename InputIterator>
	    void addRange(InputIterator begin, InputIterator end) {
	        while (begin != end) {
	            addNumber(*begin);
	            ++begin;
	        }
	    }
};
