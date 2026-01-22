#include"Bureaucrat.hpp"
int main()
{
    // try
    // {
    //     Bureaucrat a("imane",1);
    //     std::cout << a ;
    //     a.decrementGrade();
    //     std::cout << a ;
    //     a.incrementGrade();
    //     a = Bureaucrat("d", 4);
    //     std::cout << a ;
    //     a.incrementGrade();
    //     std::cout << a ;
    // }
    
    // catch(Bureaucrat::GradeTooHighException &e)
    // {
    //     std::cout<<e.what()<<std::endl;
    // }
    // catch(Bureaucrat::GradeTooLowException &e)
    // {
    //     std::cout<<e.what()<<std::endl;
    // }

    // try
    // {
    //     Bureaucrat invalid("d", 263484);
    // }
    // catch(Bureaucrat::GradeTooHighException &e)
    // {
    //     std::cout<<e.what()<<std::endl;
    // }
    // catch(Bureaucrat::GradeTooLowException &e)
    // {
    //     std::cout<<e.what()<<std::endl;
    // }


    try
    {
        Bureaucrat a("imane",111);
        Form b("iqor",111,111);
        b.beSigned(a);
        b.beSigned(a);
        b.beSigned(a);
        std::cout<<b.getBool()<<std::endl;
        a.signForm(b);
        std::cout<<b.getBool()<<std::endl;

    }
    catch(Form::GradeTooHighException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}
