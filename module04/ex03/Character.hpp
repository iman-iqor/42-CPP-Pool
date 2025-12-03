#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include"ICharacter.hpp"
#include"AMateria.hpp"

class Character :public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();
        virtual std::string const & getName() const;//returning a reference means:I’m giving you access to the actual string stored inside the object, without copying it.const: I promise not to change that string through this reference.
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif