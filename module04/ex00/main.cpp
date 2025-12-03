#include"Animal.hpp"
#include"Dog.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"

int main()
{
    Animal a;
    a.makeSound();
    Dog d;
    d.makeSound();
    Cat c;
    c.makeSound();
    WrongCat wc;
    wc.makeSound();
    //subtype polymorphism
    Animal* animals[4];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Animal();
    for (int i = 0; i < 4; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 4; i++)
    {
        delete animals[i];
    }   
    
    
    return 0;
}