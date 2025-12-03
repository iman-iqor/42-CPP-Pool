#include"Ice.hpp"

Ice::Ice() : AMateria()
{
    type = "ice";
    //std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria()
{
    type = other.type;
    //std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice()
{
    //std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    AMateria::use(target);
}