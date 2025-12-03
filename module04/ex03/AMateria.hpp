#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include"iostream"
#include"string"
#include"ICharacter.hpp"


class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(const std::string&type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type string //std::string const & means you return a reference to a constant string.
        virtual AMateria* clone() const = 0;// pure virtual function that returns a new instance of the same materia
        virtual void use(ICharacter& target);//prints the message: "* uses <type> on <target's name> *"
        
};

#endif




