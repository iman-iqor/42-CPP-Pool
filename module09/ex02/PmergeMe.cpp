#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include "PmergeMe.hpp"
#include <utility>

int main(int argc,char** argv)
{
    (void) argc;
    (void) argv;
    int array[] =  {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
    std::vector<int> v(array,array+(sizeof(array)/sizeof(int)));
    std::vector<std::pair<int,int> > paires;
    int lenght = v.size();
    // std::cout<<lenght<<std::endl;
    if(lenght%2 != 0)
    {
        int last = v[lenght-1];
        (void) last;
        v.pop_back();
    }
    // std::cout<<v.size()<<std::endl;

    std::pair<int,int> tmp;
    for(size_t i = 0;i < v.size();i++)
    {
        tmp.first = v[i];
        tmp.second = v[++i];
        paires.push_back(tmp);
    }
    for(size_t i = 0;i < paires.size();i++)
    {
        if(paires[i].first>paires[i].second)
        {
            int tmp = paires[i].first;
            paires[i].first = paires[i].second;
            paires[i].second = tmp;
        }
    }
    for(size_t i = 0;i < paires.size();i++)
    {
        std::cout<<paires[i].first<<" "<< paires[i].second<<std::endl;
    }

}