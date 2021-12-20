#include "mutantstack.hpp"
#include <list>


void print(int it)
{
   std::cout << it << std::endl;
}

int main()
{
    Mutantstack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    Mutantstack<int>::iterator it = mstack.begin();
    Mutantstack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "********** looping on iterators **********" << std::endl;
    while(it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "********** for_each on it range **********" << std::endl;
    for_each(mstack.begin(), mstack.end(), print);
    std::cout << "********** for_each on rit range *********" << std::endl;
    for_each(mstack.rbegin(), mstack.rend(), print);
    return 0;
}