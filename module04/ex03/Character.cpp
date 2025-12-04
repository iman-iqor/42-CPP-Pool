#include"Character.hpp"

Character::Character()
{
    name = "default";
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const std::string& name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL; 
}

Character::Character(const Character& other)
{
    name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if(this != &other)
    {
        name = other.name;
        for(int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i]; // delete existing materia to avoid memory leak
            inventory[i] = NULL; // reset the pointer
        }
        for(int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i]; // delete each materia in the inventory
    }
}
std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for(int i = 0;i < 4;i++)
    {
        if(inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4)
    {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx,ICharacter& target)
{
    if(idx >= 0 && idx < 4 && inventory[idx] != NULL)
    {
        inventory[idx]->use(target);
    }
}
