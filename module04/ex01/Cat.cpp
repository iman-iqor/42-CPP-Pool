#include "Cat.hpp"
Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other)
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

        Animal::operator=(other);
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
