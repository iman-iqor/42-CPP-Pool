#include"PresidentialPardonForm.hpp"
#include"Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm",25,5),target("default")
{}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm",25,5),target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :AForm(other),target(other.target)
{}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if(this->getBool() == false)
        throw AForm::NotSignedException();
    else if(executor.getGrade() > this->getToExecute())
    {
        throw AForm::GradeTooLowException();
    }
    else
    {
        std::cout<<target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
    }
}