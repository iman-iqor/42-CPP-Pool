#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const Animal& other)
{
    type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType()
{
    return type;
}
void Animal::setType(const std::string& t)
{
    type = t;
}
void Animal::makeSound()
{
    std::cout<< type <<" sound"<<std::endl;
}