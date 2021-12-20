#ifndef SPAN_H
#define SPAN_H

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

int randomNumber();
int randomNumberInRange();

class span
{
    private:
        std::vector<int> _vector;
        unsigned int _size;
        class OutOfLimitsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class fillArrayException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class emptyArrayException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    public:
        span(void);
        span(unsigned int n);
        span(unsigned int n, int min, int max);
        span(span const & rhs);
        span & operator=(span const & rhs);
        ~span(void);
        unsigned int size() const;
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        std::vector<int> & getVector();
        void addNumbers(std::vector<int>::iterator const & begin, std::vector<int>::iterator const & end);
        void addNumbersInRange(std::vector<int>::iterator const & begin, std::vector<int>::iterator const & end);
        void printVector();
};

#endif