#include "span.hpp"

const char* span::OutOfLimitsException::what() const throw()
{
    return "Array element exception: out of limits!";
}

const char* span::fillArrayException::what() const throw()
{
    return "array already full";
}

const char* span::emptyArrayException::what() const throw()
{
    return "array empty";
}

span::span(void) : _vector(0), _size(0)
{

}

span::span(unsigned int n) : _size(n)
{
    std::vector<int> myvector;
    int *p = 0;
    
    p = myvector.get_allocator().allocate(_size);
}

span::span(span const & rhs) : _size(rhs._size)
{
    std::vector<int> myvector;
    int *p = 0;
    
    p = myvector.get_allocator().allocate(_size);
}

span & span::operator=(span const & rhs)
{
    new (this) span(rhs);
    return *this;
}

span::~span(void)
{

}

unsigned int size() const
{
    return _size;
}

void addNumber(int n)
{
    try
    {
        _vector.push_back(n);
    }
    catch (std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int shortestSpan()
{
    try
    {
        _vector.sort();
    }
    catch (std::logic_error &e)
    {
        std::cout << e.what << std::endl;
    }
    return _vector.begin() + 1 - vector._begin;
}

int longestSpan()
{
    int min = 0;
    int max = 0;

    try
    {
        min = _vector.min_element();
        max = _vector.max_element();
    }
    catch (std::logic_error &e)
    {
        std::cout << e.what << std::endl;
    }
    return max - min;
}

std::vector<int> & span::getvector()
{
    return _vector;
}