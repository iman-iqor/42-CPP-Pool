#include"Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat a("imane",1);
        std::cout << a ;
        a.decrementGrade();
        std::cout << a ;
        a.incrementGrade();
        a = Bureaucrat("d", 4);
        std::cout << a ;
        a.incrementGrade();
        std::cout << a ;
        a = Bureaucrat("d", 263484);
    }
    
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}
