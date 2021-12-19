#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

class span
{
    private:
        std::vector<int> _vector;
        unsigned int _size;
        class OutOfLimitsException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Array element exception: out of limits!";
                }
        };
        class fillArrayException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "array already full";
                }
        };
        class emptyArrayException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "array empty";
                }
        };
    public:
        span(void);
        span(unsigned int n);
        span(span const & rhs);
        span & operator=(span const & rhs);
        ~span(void);
        unsigned int size() const;
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        std::vector<int> & getvector();
};

#endif