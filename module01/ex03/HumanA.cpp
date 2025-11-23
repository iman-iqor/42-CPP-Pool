#include"Weapon.hpp"
#include"HumanA.hpp"

void HumanA::attack()
{
    std::cout<<this->name<<" attacks with their "<<this->weapon.getType()<<std::endl;
}
HumanA::HumanA(std::string n, Weapon& w) : name(n), weapon(w)
{
}