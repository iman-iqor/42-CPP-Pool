#include"Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat a("imane",57);
        std::cout << a.getGrade() << std::endl;
        a.decrementGrade();
        std::cout << a.getGrade() << std::endl;
        a.incrementGrade();
        std::cout << a.getGrade() << std::endl;
        
        a = Bureaucrat("d", 44);
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
