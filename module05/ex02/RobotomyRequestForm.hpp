#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm(){}
        void execute(Bureaucrat const & executor) const;
        class RobotomyFailedException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Robotomy failed!";
                }
        };
};





#endif