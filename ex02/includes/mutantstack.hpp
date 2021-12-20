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

	    iterator begin() { return this->c.begin(); }
	    iterator end() { return this->c.end(); }
        iterator rbegin() {return this->c.begin();}
        iterator rend() {return this->c.end();}
        iterator cbegin() {return this->c.begin();}
        iterator cend() {return this->c.end();}
        iterator crbegin() {return this->c.begin();}
        iterator crend() {return this->c.end();}
        iterator& operator++() {iterator tmp = this->c.begin(); this->c.begin()++; return tmp;}
        iterator& operator--() {iterator tmp = this->c.end();; this->c.end()--; return tmp;}
        iterator operator++(int) {++this->c.begin(); return this->c.begin();}
        iterator operator--(int) {--this->c.end();; return this->c.end();}
        bool operator==(iterator other) const {return *this == *other;}
        bool operator!=(iterator other) const {return !(*this == *other);}
        Mutantstack<T> operator*() const {return *this;}
        Mutantstack(void) {}
        Mutantstack(Mutantstack const & rhs) {(void)rhs; new (this) Mutantstack();}
        Mutantstack & operator=(Mutantstack const & rhs) {new (this) Mutantstack(rhs); return *this;}
        ~Mutantstack(void) {}
};

template< typename T >
std::ostream & operator<<(std::ostream & o, Mutantstack<T> const & rhs)
{
    o << rhs._iterator;
    return o;
}

#endif