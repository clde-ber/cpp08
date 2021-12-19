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
    _vector = std::vector<int>(_size);
    /*
    _p = _vector.get_allocator().allocate(_size);
    for (unsigned int i = 0; i < _size; i++)
        _vector.get_allocator().construct(&_p[i],0);
      std::cout << "The allocated array contains:";
    for (unsigned int i=0; i<_size; i++) std::cout << ' ' << _p[i];
    std::cout << '\n';*/
}
/*
span::span(unsigned int n, int min, int max) : _size(n)
{
    span(n);
}*/

span::span(span const & rhs) : _size(rhs._size)
{
    new (this) span(_size);
}

span & span::operator=(span const & rhs)
{
    new (this) span(rhs);
    return *this;
}

span::~span(void)
{
    /*for (unsigned int i = 0; i < _size; i++)
        _vector.get_allocator().destroy(&_p[i]);
    _vector.get_allocator().deallocate(_p, _size);*/
}

unsigned int span::size() const
{
    return _size;
}

void span::addNumber(int n)
{
    //if (_vector.size() >= _size)
        //throw fillArrayException();
    _vector.push_back(n);
}

int span::shortestSpan()
{
    int min_span = 0;

    std::cout << "SIZE = " << _size << std::endl;
    if (_size < 2)
        throw emptyArrayException();
    std::sort(_vector.begin(), _vector.end());
    min_span = std::abs(_vector[0] - _vector[1]);
    for (unsigned long i = 0; i + 1 < _size; i++)
    {
        std::cout << "essai" << std::endl;
        if (std::abs(_vector[i] - _vector[i + 1]) < min_span)
            min_span = std::abs(min_span = _vector[i] - _vector[i + 1]);
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

int & span::getP()
{
    return *_p;
}

void span::addNumbers(std::vector<int>::iterator const & begin, std::vector<int>::iterator const & end)
{
	std::generate(begin, end, randomNumber);
}

void span::printVector()
{
    for (unsigned int i = 0; i < _size; i++)
        std::cout << _vector[i] << std::endl;
}
