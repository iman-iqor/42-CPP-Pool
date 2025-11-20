#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include<iostream>
#include<string>

class Zombie{

    private:
        std::string name;
    public:
        Zombie(std::string n)
        {
            name = n;
        }
        ~Zombie()
        {
            std::cout<<name<<" is destroyed"<<std::endl;
            
        }
};

#endif