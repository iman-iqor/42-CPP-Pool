#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include "PmergeMe.hpp"
#include <utility>

int binarySearchPosition(std::vector<int> &v, int value)
{
    int left = 0;
    int right = v.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] < value)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return left;
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int array[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    std::vector<int> v(array, array + (sizeof(array) / sizeof(int)));
    std::vector<std::pair<int, int>> paires;
    int lenght = v.size();
    // std::cout<<lenght<<std::endl;
    if (lenght % 2 != 0)
    {
        int last = v[lenght - 1];
        (void)last;
        v.pop_back();
    }
    // std::cout<<v.size()<<std::endl;

    std::pair<int, int> tmp;
    for (size_t i = 0; i < v.size(); i++)
    {
        tmp.first = v[i];
        tmp.second = v[++i];
        paires.push_back(tmp);
    }
    for (size_t i = 0; i < paires.size(); i++)
    {
        if (paires[i].first > paires[i].second)
        {
            int tmp = paires[i].first;
            paires[i].first = paires[i].second;
            paires[i].second = tmp;
        }
    }
    // sort the pairs
    size_t i = 0;
    while (i < paires.size())
    {
        size_t j = 0;
        while (j < paires.size() - 1 - i)
        {
            if (paires[j].second > paires[j + 1].second)
            {
                std::swap(paires[j], paires[j + 1]);
            }
            j++;
        }
        i++;
    }
    std::vector<int> mainChain;
    for (size_t i = 0; i < paires.size(); i++)
    {
        mainChain.push_back(paires[i].second);
    }
    std::vector<int> smallElements;
    for (size_t i = 0; i < paires.size(); i++)
    {
        smallElements.push_back(paires[i].first);
    }
    mainChain.insert(mainChain.begin(), smallElements[0]);
    
    for (size_t i = 1; i < paires.size(); i++)
    {
        int index = binarySearchPosition(mainChain, paires[i].first);
        mainChain.insert(mainChain.begin() + index, paires[i].first);
    }

    for (size_t i = 0; i < mainChain.size(); i++)
    {
        std::cout << mainChain[i] << std::endl;
    }
    for (size_t i = 0; i < paires.size(); i++)
    {
        std::cout << paires[i].first << " " << paires[i].second << std::endl;
    }
}