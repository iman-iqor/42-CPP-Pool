#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
int main()
{
    


    try
    {
        /* TEST SHRUBBERY*/
        Bureaucrat a("imane",130);
        AForm* b = new ShrubberyCreationForm("file");
        std::cout<<b->getBool()<<std::endl;
        a.signForm(*b);
        std::cout<<b->getBool()<<std::endl;
        b->execute(a);
        delete b;
        //////////////////////////////////////////////
        

    }
    catch(AForm::GradeTooHighException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch(AForm::NotSignedException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}
