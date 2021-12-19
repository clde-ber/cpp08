#include "span.hpp"

int randomNumber()
{
	return (std::rand()%100);
}

int main()
{
	std::srand(std::time(NULL));

	span span(10000);
	
	span.addNumber(span.getVector().begin(), span.getVector().end(), rand());
	std::cout << "short span = " << span.shortestSpan() << std::endl;
	std::cout << "long span = " << span.longestSpan() << std::endl;
    return 0;
}
