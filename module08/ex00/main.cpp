#include"easyfind.hpp"
#include<vector>
#include<deque>
#include<list>


void test1()
{
      const std::vector<int> vec(3);
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);

    try{
        std::cout<<*easyfind(vec,0)<<std::endl;
    }
    catch( const std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}
void test2()
{
    std::deque<int> deq(3);
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);

    try{
        std::cout<<*easyfind(deq,2)<<std::endl;
    }
    catch( const std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}

void test3()
{
    std::list<int> lst(3);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try{
        std::cout<<*easyfind(lst,3)<<std::endl;
    }
    catch( const std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}


int main()
{
    test1();
    test2();
    test3();
    return 0;
}