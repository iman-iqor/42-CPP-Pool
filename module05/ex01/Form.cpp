#include"Form.hpp"
Form::Form() :name("Default"),isSigned(false),toSign(150),toExecute(150)
{}
Form::Form(const std::string& name,const int toSign,const int toExecute):name(name),isSigned(false),toSign(toSign),toExecute(toExecute)
{
    if (toSign < 1 || toExecute < 1)
        throw Form::gradeTooHighException();
    else if(toSign > 150 || toExecute > 150)
         throw Form::gradeTooLowException();
    
}

Form::Form(const Form& other):name(other.name),toSign(other.toSign),toExecute(other.toExecute),isSigned(other.isSigned)
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

const int Form::getToSign() const
{
    return toSign;
}

const int Form::getToExecute() const
{
    return toExecute;
}

void Form::beSigned(const Bureaucrat& obj)
{
    if(obj.getGrade() >=this->toSign )
        this->isSigned = true;
    else
        throw Form::gradeTooLowException();
}

