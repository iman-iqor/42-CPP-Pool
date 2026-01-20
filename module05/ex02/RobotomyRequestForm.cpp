#include"RobotomyRequestForm.hpp"
#include"Bureaucrat.hpp"

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
        throw RobotomyRequestForm::RobotomyFailedException();
    std::cout << "* drilling noises *" << std::endl;
    srand(time(0));
    int random = rand() % 2;
    if(random == 0)
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    else
}