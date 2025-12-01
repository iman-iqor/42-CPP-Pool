#include"ScavTrap.hpp"

//adding ClapTrap() in the initializer list calls the parent class constructor first
ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

//calling the parent class parameterized constructor to initialize the name member
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

//copy constructor takes a reference to onother ScavTrap object to not cause infinite recursion
//it calls the parent class copy constructor to initialize the inherited members
//then it uses the assignment operator to copy the rest of the members
//we r returning *this to allow chained assignments like a = b = c;
//there is no return typed for constructors
//const because we dont want to modify the other object
ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

//assignement operator can not use initializer list because it is not a constructor
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " has no energy or hit points left to attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
