#include "span.hpp"

void test1()
{
    Span s(10000);
    for (size_t i = 0; i < 10000; i++)
    {
        s.addNumber(i);
    }
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
}
void test2()
{
    Span s(5);
    try
    {
        s.addNumber(-1);
        s.addNumber(-1);
        s.addNumber(8);
        s.addNumber(9);
        s.addNumber(10);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
}
void test3()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}
void test4()
{
    Span s(1000);
    std::vector<int> v;
    for(int i = 0; i < 1000;i++)
    {
        v.push_back(i);
    }
    s.addNumber(v.begin(),v.end());
    
     std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
}

int main()
{
    test4();
}