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
    std::vector<int> vcr;
    n = 5;
    
     for (unsigned int i = 0; i < 5; i++)
        vcr.push_back(n += 5);
    try
    {
        std::cout << easyfind(vcr, 15) << std::endl;
        std::cout << easyfind(vcr, -5) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}