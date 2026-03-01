
#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cout<<"error"<<std::endl;
        return 1;
    }
   
    std::vector<int> v = parsing<std::vector<int> >(argc,argv);
    std::deque<int> d = parsing<std::deque<int> >(argc,argv);
    if(v.empty() || d.empty())
    {
        std::cout<<"error"<<std::endl;
        return 1;
    }

    printBefore(v);

    double dStart = clock();
    std::deque<int> sortedD = sortContainer(d);
    double dEnd = clock();

    double vStart = clock();
    std::vector<int> sortedV = sortContainer(v);
    double vEnd = clock();

    printMainChain(sortedV);

    double dTimeTaken = double(dEnd - dStart) / CLOCKS_PER_SEC* 1000000;// convert to microseconds//CLOCKS_PER_SEC is the number of clock ticks per second
    double vTimeTaken = double(vEnd - vStart) / CLOCKS_PER_SEC* 1000000;// convert to microseconds//CLOCKS_PER_SEC is the number of clock ticks per second
    std::cout << "Time taken to sort using deque: " << dTimeTaken << " us" << std::endl;
    std::cout << "Time taken to sort using vector: " << vTimeTaken << " us" << std::endl;
    
    return 0;
}