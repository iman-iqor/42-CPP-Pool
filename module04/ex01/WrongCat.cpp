#include "WrongCat.hpp"
WrongCat::WrongCat()
{
    type = "WrongCat";
    brain = new Brain();
    std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    //WRONG CAT SHALLOW COPY
    brain = other.brain;
    std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(this != &other)
    {
        //WRONG CAT SHALLOW COPY
        brain = other.brain;
        WrongAnimal::operator=(other);
    }
    return *this;
}
WrongCat::~WrongCat()
{
    //WRONG cat do not delete brain
    std::cout << "WrongCat destructor called" << std::endl;
}
void WrongCat::makeSound()
{
    std::cout << "Wrong Meow Meow" << std::endl;    
}           





