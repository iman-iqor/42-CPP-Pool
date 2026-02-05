#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>// for std::sort and std::adjacent_difference

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _numbers;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);

        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        template<typename I>
        void addNumber(I begin,I end)
        {
            for(I it = begin;it != end;it++)
            {
                addNumber(*it);
            }
        }
};

#endif