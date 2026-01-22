
#include"Intern.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern& other)
{
    (void)other;//avoid unused parameter warn
}
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}
Intern::~Intern()
{
}


 AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

 AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

 AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName,const std::string& target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string&) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    throw FormNotFoundException();
    
    return NULL;
}
