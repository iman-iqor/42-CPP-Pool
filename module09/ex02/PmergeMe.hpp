#include <utility>
#include<sstream>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>


template <typename Container>
Container parsing(int argc, char **argv)
{
    Container v;
    for (int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        int value;
        ss>>value;
        if(ss.fail() || !ss.eof() || value < 0)
        {
            return Container();
        }
        v.push_back(value);
    }
    return v;
}

template <typename Container>
std::vector<std::pair<int, int> > createPair(Container&v)
{
    std::pair<int, int> tmp;
    std::vector<std::pair<int, int> > paires;
    for (size_t i = 0; i < v.size(); i++)
    {
        tmp.first = v[i];
        tmp.second = v[++i];
        paires.push_back(tmp);
    }
    return paires;
}

template <typename Container>
Container sortInsidePairs(Container &paires)
{
    for (size_t i = 0; i < paires.size(); i++)
    {
        if (paires[i].first > paires[i].second)
        {
            int tmp = paires[i].first;
            paires[i].first = paires[i].second;
            paires[i].second = tmp;
        }
    }
    return paires;
}

template <typename Container>
Container sortPaires(Container &paires)
{
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
    return paires;
}

template <typename Container>
Container createMainChain(std::vector<std::pair<int, int> > paires)
{
    Container mainChain;
    for (size_t i = 0; i < paires.size(); i++)
    {
        mainChain.push_back(paires[i].second);
    }
    mainChain.insert(mainChain.begin(), paires[0].first);
    return mainChain;
}

template <typename Container>
Container createSmallElements(std::vector<std::pair<int, int> > paires)
{
    Container smallElements;
    for (size_t i = 1; i < paires.size(); i++)
    {
        smallElements.push_back(paires[i].first);
    }
    return smallElements;
}
template<typename Container>
Container generateJacobsthal(size_t pairsCount)
{
    Container jacob;

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


template<typename Container>
Container generateTrueOrder(Container jacob, Container smallElements)
{
    Container order ;
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
    return order;
}

template <typename Container>
int binarySearchPosition(Container &v, int value)
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

template<typename Container>
void buildFinalChain(Container &order,Container &smallElements,Container &mainChain,bool odd,int last)
{
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t index = order[i];

        int value = smallElements[index];

        int pos = binarySearchPosition(mainChain, value);

        mainChain.insert(mainChain.begin() + pos, value);
    }
    if(odd)
    {
        int index = binarySearchPosition(mainChain,last);
        mainChain.insert(mainChain.begin() + index,last);
    }
}
template<typename Container>
void printMainChain(Container mainChain)
{
    std::cout<<"After:  ";
     for(size_t i = 0;i < mainChain.size();i++)
    {
        std::cout<<mainChain[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename Container>
void printBefore(Container v)
{
    std::cout<<"Before: ";
    for(size_t i = 0;i < v.size();i++)
    {
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename Container>
Container sortContainer(Container& c)
{
    int lenght = c.size();
    bool odd = false;
    int last = 0;
    if (lenght % 2 != 0)
    {
        last = c[lenght - 1];
        (void)last;
        c.pop_back();
        odd = true;
    }


    std::vector<std::pair<int, int> > paires=createPair(c);


    paires = sortInsidePairs(paires);
    paires = sortPaires(paires);

    Container mainChain = createMainChain<Container>(paires);

    Container smallElements=createSmallElements<Container>(paires);
    

    Container jacob = generateJacobsthal<Container>(smallElements.size());
    
    Container order = generateTrueOrder<Container>(jacob,smallElements);
    
    buildFinalChain<Container>(order,smallElements,mainChain,odd,last);  
    return mainChain;
}