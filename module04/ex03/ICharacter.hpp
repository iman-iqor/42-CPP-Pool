#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include"iostream"
#include"string"
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;//returning a reference means:I’m giving you access to the actual string stored inside the object, without copying it.const: I promise not to change that string through this reference.
        virtual void equip(class AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};
#endif