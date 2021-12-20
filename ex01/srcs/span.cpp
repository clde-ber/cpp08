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

span::span(void) : _size(0)
{

}

span::span(unsigned int n) : _size(0)
{
    _vector = std::vector<int>(n);
}

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
}

unsigned int span::size() const
{
    return _size;
}

void span::addNumber(int n)
{
    if (_size + 1 > _vector.size())
        throw fillArrayException();
    _vector.push_back(n);
    _size++;
}

int span::shortestSpan()
{
    int min_span = 0;

    if (_size < 2)
        throw emptyArrayException();
    std::sort(_vector.begin(), _vector.end());
    min_span = std::abs(_vector[0] - _vector[1]);
    for (unsigned long i = 0; i + 1 < _size; i++)
    {
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

void span::addNumbers(std::vector<int>::iterator const & begin, std::vector<int>::iterator const & end)
{
    std::cout << "vector size " << _vector.size() << std::endl;
    std::cout << "size " << _size << std::endl;
    if (_size + _vector.size() > _vector.size())
        throw fillArrayException();
    std::generate(begin, end, randomNumber);
    _size += _vector.size();
}

void span::addNumbersInRange(std::vector<int>::iterator const & begin, std::vector<int>::iterator const & end)
{
    std::cout << "vector size " << _vector.size() << std::endl;
    std::cout << "size " << _size << std::endl;
    if (_size + _vector.size() > _vector.size())
        throw fillArrayException();
    std::generate(begin, end, randomNumberInRange);
}

void span::printVector()
{
    for (unsigned int i = 0; i < _size; i++)
        std::cout << _vector[i] << std::endl;
}
