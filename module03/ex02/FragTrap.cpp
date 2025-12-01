#include"FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout<< "FragTrap Default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    std::cout<<"FragTrap Parameterized constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
    std::cout<<"FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout<<"FragTrap copy assignement operator called"<<std::endl;
    if(this != &other)
    {
        this->name = other.name;
        this->hitPoints= other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap Destructor called"<<std::endl;
}
void FragTrap::highFivesGuys()
{
    std::cout<<"FragTrap "<< name <<" is requesting a high five!"<<std::endl;
}