#ifndef ICE_HPP
#define ICE_HPP
#include"AMateria.hpp"

class Ice :public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        virtual ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);//i need to override use to call the base class implementation
        
};

#endif