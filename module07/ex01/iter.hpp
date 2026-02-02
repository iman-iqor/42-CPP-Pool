#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>
#include<string>

template<typename T>
void iter(T* array,const size_t lengh,void (*func)(T&))
{
    for(size_t i = 0; i < lengh; i++)
    {
        func(array[i]);
    }
}

template<typename T>
void iter(const T* array,const size_t lengh,void (*func) (const T&))
{
    for(size_t i = 0; i < lengh; i++)
    {
        func(array[i]);
    }
}

template<typename T>
void print(const T& x)
{
    std::cout<<x<<std::endl;
}

template<typename T>
void increment( T& x)
{
    x++;
}


#endif