#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <exception>
class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int toSign;
        const int toExecute;
    public:
        Form();
        Form(const std::string& name,const int toSign,const int ToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form(){};

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
        
};

std::ostream& operator<<(std::ostream &out,const Form& obj);

#endif