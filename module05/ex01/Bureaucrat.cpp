#include"Bureaucrat.hpp"
Bureaucrat::Bureaucrat():name("Default"),grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string& name,int grade):name(name)
{
    if(grade < 1 )
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    this->grade = grade;

}
Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name),grade(other.grade)
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if(this->grade <= 1)
        throw GradeTooHighException();
    this->grade--;
}
void Bureaucrat::decrementGrade()
{
    if(this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm( Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const Form::GradeTooLowException &)
    {
        std::cout << this->name << " couldn't sign " << form.getName() << " because his grade is too low." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& obj)
{
    out << obj.getName()<<", bureaucrat grade " <<obj.getGrade()<<std::endl;
    return out;
}