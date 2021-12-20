#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <stack>

template< typename T >
class Mutantstack : public std::stack<T>
{
    public :
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        Mutantstack(void) {}
        Mutantstack(Mutantstack const & rhs) 
        {
            (void)rhs;
            new (this) Mutantstack();
        }
        Mutantstack & operator=(Mutantstack const & rhs)
        {
            new (this) Mutantstack(rhs);
            return *this;
        }
        ~Mutantstack(void) {}
	    iterator begin()
        {
            return this->c.begin();
        }
	    iterator end()
        {
            return this->c.end();
        }
        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }
        reverse_iterator rend()
        {
            return this->c.rend();
        }
};

#endif