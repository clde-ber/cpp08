#include "span.hpp"

int randomNumber()
{
    return std::rand()%100;
}

int main()
{
	std::srand(std::time(NULL));
	
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "********** printvector **********" << std::endl;
		sp.printVector();
		std::cout << "short span = " << sp.shortestSpan() << std::endl;
		std::cout << "long span = " << sp.longestSpan() << std::endl;
		sp.addNumber(0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Span span(15);
	try
	{
		span.addNumbers(span.getVector().begin(), span.getVector().end());
		std::cout << "********** printvector **********" << std::endl;
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
		span.addNumbers(span.getVector().begin(), span.getVector().end());
		std::cout << "********** printvector **********" << std::endl;
		span.printVector();
		std::cout << "short span = " << span.shortestSpan() << std::endl;
		std::cout << "long span = " << span.longestSpan() << std::endl;
		span.addNumber(-15);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Span empty = Span(1);
	try
	{
		empty.addNumber(0);
		empty.shortestSpan();
		empty.longestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Span bigSpan(10000);
	try
	{
		bigSpan.addNumbers(bigSpan.getVector().begin(), bigSpan.getVector().end());
		std::cout << "********** printvector **********" << std::endl;
		bigSpan.printVector();
		std::cout << "short span = " << bigSpan.shortestSpan() << std::endl;
		std::cout << "long span = " << bigSpan.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}