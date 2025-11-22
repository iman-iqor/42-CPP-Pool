#include"Zombie.hpp"
void Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie()
{
    std::cout<<name<<" is destroyed"<<std::endl;
}

Zombie::Zombie(){}

void Zombie::setName(std::string n)
{
    name = n;
}
std::string Zombie::getName(void)
{
    return name;
}