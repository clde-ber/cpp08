#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>

template< typename T >
int & easyfind(T & const lhs, int n)
{
    typename T::iterator it = T.begin();
    typename T::iterator ite = T.end();
    return std::find(it, ite, n);
}

template< typename T >
class notFoundException : public std::exception
{
    public :
        virtual const char* what() const throw()
        {
            return "Element not found exception!";
        }
};

#endif