#include "easyfind.hpp"

int main()
{
    std::list<int> lst;
    int n = 10;
    
    for (unsigned int i = 0; i < 5; i++)
        lst.push_back(n += 10);
    try
    {
        std::cout << easyfind(lst, 30) << std::endl;
        std::cout << easyfind(lst, 0) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

void test_empty_list()
{
	std::cout << "TEST empty list" << std::endl;
	std::list<int> lst;
	try
	{
		easyfind(lst, 42);
		std::cout << "should never see this" << std::endl;
	}
	catch (std::exception & e){std::cout << e.what() << std::endl;}
	std::cin.get();
}

/*
void test_list_square(int n)
{
	std::cout << "TEST list of int" << std::endl;
	std::list<int> lst;
	int result;
	std::cout << "list : ";
	for(int i = 0; i <= 10; i++)
	{
		lst.push_back(i*i);
		std::cout << i*i << " ";
	}
	std::cout <<  std::endl;

	try
	{
		std::cout << "search for " << n << " in the list" << std::endl;
		result = easyfind(lst, n);
		std::cout << result << " in the list" << std::endl;
	}
	catch (std::exception & e){std::cout << e.what() << std::endl;}
	std::cin.get();
}

int main()
{
	test_list_square(14);
	test_list_square(25);
	test_empty_list();
}*/