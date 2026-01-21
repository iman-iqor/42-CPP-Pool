#include"RobotomyRequestForm.hpp"
#include"Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm",72,45),target("default")
{}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm",72,45),target(target)
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other),target(other.target)
{}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(this->getBool() == false)
        throw AForm::NotSignedException();
   else if(executor.getGrade() > this->getToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;    
    int random = rand() % 2;
    if(random == 0)
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << this->target << "." << std::endl;
}