#include"AForm.hpp"
#include"Bureaucrat.hpp"
AForm::AForm() :name("Default"),isSigned(false),toSign(150),toExecute(150)
{}
AForm::AForm(const std::string& name,const int toSign,const int toExecute):name(name),isSigned(false),toSign(toSign),toExecute(toExecute)
{
    if (toSign < 1 || toExecute < 1)
        throw AForm::GradeTooHighException();
    else if(toSign > 150 || toExecute > 150)
         throw AForm::GradeTooLowException();
    
}

AForm::AForm(const AForm& other):name(other.name),isSigned(other.isSigned),toSign(other.toSign),toExecute(other.toExecute)
{}
AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
        isSigned = other.isSigned;
    return *this;
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getBool() const
{
    return isSigned;
}

int AForm::getToSign() const
{
    return toSign;
}

int AForm::getToExecute() const
{
    return toExecute;
}

void AForm::beSigned(const Bureaucrat& obj)
{
    if(obj.getGrade() <= this->toSign )
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out,const AForm& obj)
{
    out << "AForm name: " << obj.getName() << ", is signed: " << std::boolalpha << obj.getBool() << ", grade required to sign: " << obj.getToSign() << ", grade required to execute: " << obj.getToExecute() << std::endl;
    return out;
}


