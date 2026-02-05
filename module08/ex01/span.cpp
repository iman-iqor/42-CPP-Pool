#include"span.hpp"
Span::Span(unsigned int n) : _n(n)
{
}
Span::~Span()
{}
Span::Span(const Span &other) : _n(other._n), _numbers(other._numbers)
{
}
Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {       
        _n = other._n;
        _numbers = other._numbers;
    }       
    return *this;
}

void Span::addNumber(int number)
{
    if(_numbers.size() >= _n)
    {
        throw std::runtime_error("cannot add more elements, the container is full");
    }
    _numbers.push_back(number);

}

unsigned int Span::shortestSpan() const
{
    if(_numbers.size() < 2)
        throw std::runtime_error("not enough members to get the shortest span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    unsigned int shortSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int diff = sorted[i] - sorted[i - 1];
        if (diff < shortSpan)
            shortSpan = diff;
    }
    return shortSpan;
}

unsigned int Span::longestSpan() const
{
    if(_numbers.size() < 2)
        throw std::runtime_error("not enough members to get the longest span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    unsigned int longestSpan = sorted[sorted.size()-1] - sorted[0];
    return longestSpan;
}
