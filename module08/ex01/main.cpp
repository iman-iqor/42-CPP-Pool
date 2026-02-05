#include"span.hpp"

int main()
{
    Span s(5);
    
    s.addNumber(-1);
    s.addNumber(-1);
    s.addNumber(8);
    s.addNumber(9);
    s.addNumber(10);
    
    
    std::cout<<s.shortestSpan()<<std::endl;
    std::cout<<s.longestSpan()<<std::endl;
    
}