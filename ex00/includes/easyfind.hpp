#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <vector>

template< typename T >
int const & easyfind(T & lhs, int n)
{
    typename T::const_iterator it = lhs.begin();

    it = std::find(lhs.begin(), lhs.end(), n);
    if (it == lhs.end())
        throw std::runtime_error("not found");
    return *it;
}

#endif