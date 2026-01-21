
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
AForm* Intern::makeForm(const std::string& formName,const std::string& target)
{
    std::string formNames[3] = {"shruberry creation","robotomy request","presidential pardon"};
    AForm* (*formCreators[3])(const std::string& target) = {
        [](const std::string& target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string& target) -> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string& target) -> AForm* { return new PresidentialPardonForm(target); }
    }; 
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    throw FormNotFoundException();  
            
}