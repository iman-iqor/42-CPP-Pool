#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"Intern.hpp"
int main()
{
    


    try
    {
        Intern imane;
        AForm* ref;
        ref = imane.makeForm("robotomy request","Bender");
        Bureaucrat iqor("iqor",45);
        iqor.signForm(*ref);
        iqor.executeForm(*ref);
        delete ref;
        

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
    catch(Intern::FormNotFoundException &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}
