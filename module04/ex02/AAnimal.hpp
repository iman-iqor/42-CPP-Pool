#ifndef ANIMAL_HPP
#define ANIMAL_HPP  
#include <iostream>
#include <string>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal();
        virtual void makeSound() = 0;
        std::string getType();
        void setType(const std::string& t);

        
};

#endif