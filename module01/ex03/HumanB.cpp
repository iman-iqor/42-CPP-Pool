#include"HumanB.hpp"

void HumanB::attack()
{
    if (this->weapon)
        std::cout<<this->name<<" attacks with their "<<this->weapon->getType()<<std::endl;
    else
        std::cout<<this->name<<" has no weapon to attack with"<<std::endl;
}
HumanB::HumanB(std::string N) : name(N), weapon(NULL)
{
}
void HumanB::setWeapon(Weapon& W)
{
    this->weapon = &W;
}