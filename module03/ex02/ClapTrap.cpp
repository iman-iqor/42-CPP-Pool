#include"ClapTrap.hpp"
ClapTrap::ClapTrap(): name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" <<  std::endl;
    *this = other;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}
void ClapTrap::attack(const std::string &target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

//decrease hitPoints by amount, if hitPoints < 0 set hitPoints to 0
void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)//a character in a game can’t have negative life points.
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
}

//if energyPoints or hitPoints are 0, ClapTrap cannot be repaired
//else decrease energyPoints by 1 and increase hitPoints by amount
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {   
        std::cout << "ClapTrap " << name << " has no energy or hit points left to repair." << std::endl;
        return;
    }                               
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! Current hit points: " << hitPoints << std::endl;
}
