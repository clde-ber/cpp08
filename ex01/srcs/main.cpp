#include "span.hpp"

int randomNumber()
{
	return (std::rand()%100);
}

int main()
{
	std::srand(std::time(NULL));

	span span(10000);
	// for (int i = 0; i < 10; i++)
	// 	span.addNumber(i);
	std::vector<int> test(10000);

	std::copy(span.getVector().begin(), span.getVector().end(), test.begin());
	// std::fill(test.begin(), test.end(), test.addNumber(randomNumber()));
	std::cout << "short span = " << span.shortestSpan() << std::endl;
	std::cout << "long span = " << span.longestSpan() << std::endl;
    return 0;
}
