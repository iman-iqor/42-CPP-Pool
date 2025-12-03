#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}
AAnimal::AAnimal(const AAnimal& other)
{
    type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType()
{
    return type;
}
void AAnimal::setType(const std::string& t)
{
    type = t;
}
void AAnimal::makeSound()
{
    std::cout<< type <<" sound"<<std::endl;
}