#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
int main()
{
    


    try
    {
        Bureaucrat a("imane",145);
        AForm* b = new ShrubberyCreationForm("home");
        std::cout<<b->getBool()<<std::endl;
        a.signForm(*b);
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
}
