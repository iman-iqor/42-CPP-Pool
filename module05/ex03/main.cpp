#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
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



        /*TEST ROBOTO*/
        Bureaucrat c("imane",40);
        AForm* d = new RobotomyRequestForm("robotomy");
        c.signForm(*d);
        d->execute(c);
        delete d;
        //////////////////////////////////////////////
        /*TEST PRESIDENTIAL*/
        Bureaucrat e("imane",3);
        AForm* f = new PresidentialPardonForm("presidential");
        e.signForm(*f);
        f->execute(e);
        delete f;
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
