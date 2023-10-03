#include "Span.hpp"

int main()
{
    Span span(10);
    std::vector<int> test;

    srand(time(NULL));
    try {
        for (int i = 1; i < 10; ++i) {
            test.push_back(-i * rand());
        }
        // span.addNumber(std::numeric_limits<int>::min());
        // span.addNumber(std::numeric_limits<int>::max());
        span.addRange(test.begin(), test.end());
        span.addNumber(-3);
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << span.longestSpan() << std::endl;
        test.clear();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}