#include "Cure.hpp"


Cure::Cure() : AMateria()
{
    type = "cure";
    //std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria()
{
    type = other.type;
    //std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure()
{
    //std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "*" << type<<" heals " << target.getName() << "'s wounds *" << std::endl;
}