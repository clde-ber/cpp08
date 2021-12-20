#include "span.hpp"

const char* Span::OutOfLimitsException::what() const throw()
{
    return "vector element exception: out of limits!";
}

const char* Span::fillArrayException::what() const throw()
{
    return "vector size exception: already full!";
}

const char* Span::notEnoughNumbersException::what() const throw()
{
    return "not enough numbers exception: cannot make span!";
}

Span::Span(void) : _size(0)
{

}

Span::Span(unsigned int n) : _size(0)
{
    _vector = std::vector<int>(n);
}

Span::Span(Span const & rhs) : _size(rhs._size)
{
    new (this) Span(_size);
}

Span & Span::operator=(Span const & rhs)
{
    new (this) Span(rhs);
    return *this;
}

Span::~Span(void)
{
}

unsigned int Span::size() const
{
    return _size;
}

void Span::addNumber(int n)
{
    if (_size + 1 > _vector.size())
        throw fillArrayException();
    _vector[_size] = n;
    _size++;
}

int Span::shortestSpan()
{
    int min_span = 0;

    if (_size < 2)
        throw notEnoughNumbersException();
    std::sort(_vector.begin(), _vector.end());
    min_span = std::abs(_vector[0] - _vector[1]);
    for (unsigned long i = 0; i + 1 < _size; i++)
    {
        if (std::abs(_vector[i] - _vector[i + 1]) < min_span)
            min_span = std::abs(min_span = _vector[i] - _vector[i + 1]);
    }
    return min_span;
}

int Span::longestSpan()
{
    if (_size < 2)
        throw notEnoughNumbersException();
    int min = *std::min_element(_vector.begin(), _vector.end());
    int max = *std::max_element(_vector.begin(), _vector.end());
    return max - min;
}

std::vector<int> & Span::getVector()
{
    return _vector;
}

void Span::addNumbers(std::vector<int>::iterator const & begin, std::vector<int>::iterator const & end)
{
    if (_size > 0)
        throw fillArrayException();
    std::generate(begin, end, randomNumber);
    _size += _vector.size();
}

void Span::printVector()
{
    std::vector<int>::iterator it = _vector.begin();
    std::vector<int>::iterator ite = _vector.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
}
