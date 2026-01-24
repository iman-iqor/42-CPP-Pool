#ifndef SCSALARCONVERTE_HPP
#define SCSALARCONVERTE_HPP

#include<string>
#include<iostream>

class ScalarConverte
{
    private:
        ScalarConverte();
        ScalarConverte(const ScalarConverte& other);
        ScalarConverte& operator=(const ScalarConverte& other);
        ~ScalarConverte();
    public:
        static void convert(std::string &input);
};

#endif