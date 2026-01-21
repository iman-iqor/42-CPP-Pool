#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include <exception>
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int toSign;
        const int toExecute;
    public:
        AForm();
        AForm(const std::string& name,const int toSign,const int ToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm(){};
        virtual void execute(Bureaucrat const & executor) const = 0;
        const std::string &getName() const;
        bool getBool() const;
         int getToSign() const;
         int getToExecute() const;

        void beSigned(const Bureaucrat& obj);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too low!";
                }
        };

        class NotSignedException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form is not signed!";
                }
        };
        
};

std::ostream& operator<<(std::ostream &out,const AForm& obj);

#endif