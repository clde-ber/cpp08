#include "span.hpp"

/*void test_10k_values()
{
	std::cout << "TEST span 10k values" << std::endl;

	std::srand(unsigned(std::time(NULL)));
	std::vector<int> v(10000);
	std::generate(v.begin(), v.end(), small_random);

	span sp = span(10000);
	sp.addNumber();
	std::cout << "short span = " << sp.shortestSpan() << std::endl;
	std::cout << "long span = " << sp.longestSpan() << std::endl;
	std::cin.get();

}*/

int main()
{
	std::srand(std::time(NULL));

	span span(10000);
	std::for_each(span.getvector().begin(), span.getvector().end(), span.addNumber(rand()));
	std::cout << "short span = " << span.shortestSpan() << std::endl;
	std::cout << "long span = " << span.longestSpan() << std::endl;
	std::cin.get();
    return 0;
}
