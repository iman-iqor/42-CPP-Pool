#include"Character.hpp"



Character::Character()
{
    name = "default";
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
}

Character::Character(const std::string& name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr; 
}

Character::Character(const Character& other)
{
    name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
}