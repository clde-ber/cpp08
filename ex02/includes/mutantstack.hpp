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
        typedef Mutantstack<T>* iterator;
        iterator _iterator;
        iterator& operator++() {iterator tmp = *this; this->_iterator++; return tmp;}
        iterator& operator--() {iterator tmp = *this; this->_iterator--; return tmp;}
        iterator operator++(int) {++this->_iterator; return *this;}
        iterator operator--(int) {--this->_iterator; return *this;}
        bool operator==(iterator other) const {return *this->_iterator == *other;}
        bool operator!=(iterator other) const {return !(*this->_iterator == *other);}
        Mutantstack<T> operator*() const {return *this->_iterator;}
        Mutantstack(void) : _iterator(0) {}
        Mutantstack(Mutantstack const & rhs) : _iterator(rhs._iterator) {}
        Mutantstack & operator=(Mutantstack const & rhs) {new (this) Mutantstack(rhs); return *this;}
        ~Mutantstack(void) {}
        iterator begin() {return this->_iterator;}
        iterator end() {std::cout << this->size() << std::endl; return this->_iterator + this->size() >= this->_iterator? this->_iterator+this->size() : this->_iterator-this->size();}
        iterator rbegin() {return this;}
        iterator rend() {return this + this->size() >= this? this-this->size() : this+this->size();}
        iterator cbegin() {return this;}
        iterator cend() {return this + this->size() >= this? this+this->size() : this-this->size();}
        iterator crbegin() {return this;}
        iterator crend() {return this + this->size() >= this? this-this->size() : this+this->size();}
};

template< typename T >
std::ostream & operator<<(std::ostream & o, Mutantstack<T> const & rhs)
{
    o << rhs._iterator;
    return o;
}

#endif