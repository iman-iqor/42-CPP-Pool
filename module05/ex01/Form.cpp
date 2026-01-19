#include"Form.hpp"
#include"Bureaucrat.hpp"
Form::Form() :name("Default"),isSigned(false),toSign(150),toExecute(150)
{}
Form::Form(const std::string& name,const int toSign,const int toExecute):name(name),isSigned(false),toSign(toSign),toExecute(toExecute)
{
    if (toSign < 1 || toExecute < 1)
        throw Form::GradeTooHighException();
    else if(toSign > 150 || toExecute > 150)
         throw Form::GradeTooLowException();
    
}

Form::Form(const Form& other):name(other.name),isSigned(other.isSigned),toSign(other.toSign),toExecute(other.toExecute)
{}
Form& Form::operator=(const Form& other)
{
    if(this != &other)
        isSigned = other.isSigned;
    return *this;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getBool() const
{
    return isSigned;
}

int Form::getToSign() const
{
    return toSign;
}

int Form::getToExecute() const
{
    return toExecute;
}

void Form::beSigned(const Bureaucrat& obj)
{
    if(obj.getGrade() <= this->toSign )
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out,const Form& obj)
{
    out << "Form name: " << obj.getName() << ", is signed: " << std::boolalpha << obj.getBool() << ", grade required to sign: " << obj.getToSign() << ", grade required to execute: " << obj.getToExecute() << std::endl;
    return out;
}


