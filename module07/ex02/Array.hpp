#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include<exception>

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _n;

public:
    Array() : _array(new T[0]), _n(0) {}
    Array(unsigned int n) : _array(new T[n]), _n(n) {}
    Array(const Array &other) : _array(new T[other._n]), _n(other._n)
    {
        for (unsigned int i = 0; i < other._n; i++)
        {
            _array[i] = other._array[i];
        }
    }
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {

            delete[] _array;
            _array = new T[other._n];
            for (unsigned int i = 0; i < other._n; i++)
            {
                _array[i] = other._array[i];
            }
            _n = other._n;
        }
        return *this;
    }
    ~Array()
    {
        delete[] _array;
    }

    const unsigned int &size() const
    {
        return _n;
    }

    T& operator[](unsigned int index)
    {
        if(index >= _n)
            throw std::out_of_range("index out of bounds!");
        return _array[index];
    }
    const  T& operator[](unsigned int index) const
    {
        if(index >= _n)
            throw std::out_of_range("index out of bounds!");
        return _array[index];
    }
};

#endif