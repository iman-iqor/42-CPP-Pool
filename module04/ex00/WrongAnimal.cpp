#include"WrongAnimal.hpp"
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    type = other.type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
    {
        type = other.type;          
    }
    return *this;
}       
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}
std::string WrongAnimal::getType()
{
    return type;
}
void WrongAnimal::setType(const std::string& t)
{
    type = t;
}
void WrongAnimal::makeSound()
{
    std::cout<< type <<" sound"<<std::endl;
}       