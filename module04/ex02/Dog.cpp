#include"Dog.hpp"

Dog::Dog(): AAnimal()
{
    type = "Dog";
    brain  = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}       
Dog::Dog(const Dog& other) : AAnimal(other)
{
    brain = new Brain();
    for(int i = 0;i < 100;i++)
    {
        brain->setIdea(i,other.brain->getIdea(i));
    }
    std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
    {
        delete brain;
        brain = new Brain();
        for(int i = 0;i < 100;i++)
        {
            brain->setIdea(i,other.brain->getIdea(i));
        }   
    }
    return *this;
}
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound()
{
    std::cout << "haw haw" << std::endl;
}
Brain* Dog::getBrain()
{
    return brain;
}
