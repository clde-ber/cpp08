#include "span.hpp"

int randomNumber ()
{
	return (std::rand()%100);
}

int main()
{
	std::srand(std::time(NULL));

	span span(10);
	for (int i = 0; i < 10; i++)
		span.addNumber(i);
//	std::generate(span.getvector().begin(), span.getvector().end(), randomNumber);
	// std::for_each(span.getvector().begin(), span.getvector().end(), span.addNumber(rand()));
	std::cout << "short span = " << span.shortestSpan() << std::endl;
	std::cout << "long span = " << span.longestSpan() << std::endl;
    return 0;
}
