#include"AAnimal.hpp"
#include"Dog.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"
#include <sstream>

int main()
{
    // Animal *ptr = new Dog();

    // ptr->makeSound();
    // delete ptr;

    // AAnimal a;
    // a.makeSound();


    // Dog d;
    // d.makeSound();
    // Cat c;
    // c.makeSound();
    // WrongCat wc;
    // wc.makeSound();
    // // subtype polymorphism
    // Animal* animals[4];
    // animals[0] = new Animal();
    // animals[1] = new Dog();
    // animals[2] = new Cat();
    // animals[3] = new Animal();
    // for (int i = 0; i < 4; i++)
    // {
    //     animals[i]->makeSound();
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     delete animals[i];
    // }   
    
    /*NORMAL TEST JUST TO SEE THE CONSTRUCTOR AND DESTRUCTOR ORDER */

    // Animal* ptr[2];
    // ptr[0] = new Dog();
    // ptr[1] = new Cat();
    // for (int i = 0; i < 2; i++)
    // {
    //     ptr[i]->makeSound();
    // }
    // for (int i = 0; i < 2; i++)
    // {
    //     delete ptr[i];
    // }
/*-------------------------------------------------------------------------------------------------------*/

    /*TESTS FOR BRAIN*/


    // Cat minouche;
    // for (int i = 0; i < 10; i++)
    // {
        
    //     minouche.getBrain()->setIdea(i, std::string("happy idea "));
    // }

    // for(int i = 0;i < 10;i++)
    // {
    //     std::cout<<"minouche idea: "<<i<< " "<<minouche.getBrain()->getIdea(i)<<std::endl;
    // }

    // Cat copyminouche(minouche);

    // for(int i = 0;i < 10;i++)
    // {
    //     std::cout<<"copyminouche idea: "<<i<< " "<<minouche.getBrain()->getIdea(i)<<std::endl;
    // }

    // Cat copyassignminouche;
    // copyassignminouche = minouche;
    // for(int i = 0;i < 10;i++)
    // {
    //     std::cout<<"copyassignminouche idea: "<<i<< " "<<minouche.getBrain()->getIdea(i)<<std::endl;
    // }
    
    //  for (int i = 0; i < 10; i++)
    // {
        
    //     copyassignminouche.getBrain()->setIdea(i, std::string("sad idea "));
    // }

    // std::cout<<"minouche idea 0: "<<copyassignminouche.getBrain()->getIdea(0)<<std::endl;
    

    /*--------------------------------------------------------------------------------------------------------*/

    /*WRONG CAT TESTS*/

    // WrongCat wrongcat1;
    // WrongCat wrongcat2 = wrongcat1;
    // delete &wrongcat1;
    // delete &wrongcat2;//it will cause a double free because of shallow copy
    /*____________________________________________________________________________________________________________*/
    

/* TEST THE AAnimal AS A ABSTRACT CLASS */


    return 0;
}