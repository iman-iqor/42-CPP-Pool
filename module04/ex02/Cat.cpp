#include "Cat.hpp"
Cat::Cat() : AAnimal() // mean to call base class default constructor then the derived class default constructor
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& other) : AAnimal(other)//mean to call base class copy constructor then the derived class copy constructor
{
    brain = new Brain();
    for(int i = 0;i < 100;i++)
    {
        brain->setIdea(i,other.brain->getIdea(i));
    }
    std::cout << "Cat copy constructor called" << std::endl;
}


Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
    {

        AAnimal::operator=(other);
        delete brain;
        brain = new Brain();
        for(int i = 0;i < 100;i++)
        {
            brain->setIdea(i,other.brain->getIdea(i));
        }
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "Meow Meow" << std::endl;
}

Brain* Cat::getBrain()
{
    return brain;
}
