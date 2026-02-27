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
std::vector<size_t> generateJacobsthal(size_t pairsCount)
{
    std::vector<size_t> jacob;

    if (pairsCount == 0)
        return jacob;

    size_t j0 = 0;
    size_t j1 = 1;

    if (j1 <= pairsCount)
        jacob.push_back(j1);

    while (1)
    {
        size_t next = j1 + 2 * j0;

        if (next > pairsCount)
            break;

        if (next != j1)  // skip duplicate 1
            jacob.push_back(next);

        j0 = j1;
        j1 = next;
    }

    return jacob;
}
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int array[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    std::vector<int> v(array, array + (sizeof(array) / sizeof(int)));
    std::vector<std::pair<int, int> > paires;
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
    mainChain.insert(mainChain.begin(), paires[0].first);
   

    std::vector<int> smallElements;
    for (size_t i = 1; i < paires.size(); i++)
    {
        smallElements.push_back(paires[i].first);
    }
 

    std::vector<size_t> jacob = generateJacobsthal(smallElements.size());


    std::vector<size_t> order;
    size_t prev = 0;

    for (size_t i = 0; i < jacob.size(); i++)
    {
        size_t current = jacob[i];

        for (size_t j = current; j > prev; j--)
            order.push_back(j - 1); // convert to 0-based

        prev = current;
    }
    
    // remaining elements
    for (size_t j = smallElements.size(); j > prev; j--)
        order.push_back(j - 1);



    for (size_t i = 0; i < order.size(); i++)
    {
        size_t index = order[i];

        int value = smallElements[index];

        int pos = binarySearchPosition(mainChain, value);

        mainChain.insert(mainChain.begin() + pos, value);
    }


}