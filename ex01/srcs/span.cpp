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
    _p = _vector.get_allocator().allocate(_size);
}

span::span(span const & rhs) : _size(rhs._size)
{
    _p = _vector.get_allocator().allocate(_size);
}

span & span::operator=(span const & rhs)
{
    new (this) span(rhs);
    return *this;
}

span::~span(void)
{
    _vector.get_allocator().deallocate(_p, _size);
}

unsigned int span::size() const
{
    return _size;
}

void span::addNumber(int n)
{
    if (_vector.size() >= _size)
    throw fillArrayException();
    _vector.push_back(n);
}

int span::shortestSpan()
{
    int min_span = 0;

    if (_size < 2)
        throw emptyArrayException();
    std::sort(_vector.begin(), _vector.end()); 
    min_span = _vector[_vector.size() - 1] - _vector[_vector.size() - 2];
    for (unsigned long i = _vector.size() - 2; i - 2 > 0; i--)
    {
        if (_vector[i] - _vector[i - 1])
            min_span = _vector[i] - _vector[i - 1];
    }
    return min_span;
}

int span::longestSpan()
{
    if (_size < 2)
        throw emptyArrayException();
    int min = *std::min_element(_vector.begin(), _vector.end());
    int max = *std::max_element(_vector.begin(), _vector.end());
    return max - min;
}

std::vector<int> & span::getVector()
{
    return _vector;
}