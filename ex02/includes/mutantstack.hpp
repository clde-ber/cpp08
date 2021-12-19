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

template< typename T>
class Mutantstack : public std::stack<T>
{
    public:
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
        Mutantstack<T>::iterator begin() {
            return this;
        }
        Mutantstack<T>::iterator end() {
            return &(this->top()) + 1;
        }/*
        Mutantstack<int>::iterator & operator++(Mutantstack<int>::iterator & rhs)
        {

        }
        Mutantstack<int>::iterator & operator--(Mutantstack<int>::iterator & rhs)
        {

        }
        Mutantstack<int>::iterator & operator!=(Mutantstack<int>::iterator & rhs)
        {

        }
        Mutantstack<int>::iterator & operator*(Mutantstack<int>::iterator & rhs)
        {

        }*/


    class iterator {
        public :
            iterator & operator++(iterator const & rhs);
            iterator & operator--(iterator const & rhs);
            iterator & operator!=(iterator const & rhs);
            iterator & operator--(iterator const & rhs);
    }
};

#endif