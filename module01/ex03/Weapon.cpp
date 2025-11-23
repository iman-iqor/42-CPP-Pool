#include"Weapon.hpp"
void Weapon::setType(std::string weaponType)
{
    this->type = weaponType;
}
const std::string& Weapon::getType()
{
    return this->type;
}