#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
    //std::cout << "AMateria default constructor called" << std::endl;
}
AMateria::AMateria(const std::string& type) : type(type)
{
    //std::cout << "AMateria parameterized constructor called" << std::endl;
}
AMateria::AMateria(const AMateria& other)
{
    type = other.type;
    //std::cout << "AMateria copy constructor called" << std::endl;
}
AMateria& AMateria::operator=(const AMateria& other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}
AMateria::~AMateria()
{
    //std::cout << "AMateria destructor called" << std::endl;
}
std::string const & AMateria::getType() const
{
    return type;
}
void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}