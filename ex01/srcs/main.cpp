#include "span.hpp"

int randomNumber()
{
    return std::rand()%100;
}

int randomNumberInRange()
{
	int min = 0;
	int max = 100;
	return (std::rand() % (max - min + 1)) + min;
}

int main()
{
	std::srand(std::time(NULL));
	span span(5);
	
	try
	{
		span.addNumbers(span.getVector().begin(), span.getVector().end());
		span.printVector();
		std::cout << "short span = " << span.shortestSpan() << std::endl;
		std::cout << "long span = " << span.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		span.addNumbersInRange(span.getVector().begin(), span.getVector().end());
		span.printVector();
		std::cout << "short span = " << span.shortestSpan() << std::endl;
		std::cout << "long span = " << span.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}