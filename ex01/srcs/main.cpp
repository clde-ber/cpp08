#include "span.hpp"
#include "utils.hpp"

int main()
{
	std::srand(std::time(NULL));
	span span(100);
	
	span.addNumbers(span.getVector().begin(), span.getVector().end());
	span.printVector();
	//std::for_each(span.getVector().begin(), span.getVector().end(), [](int i) { std::cout << i; });
	//std::cout << "short span = " << span.shortestSpan() << std::endl;
	//std::cout << "long span = " << span.longestSpan() << std::endl;
    return 0;
}