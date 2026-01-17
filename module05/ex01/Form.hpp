#ifndef FORM_HPP
#define FORM_HPP

#include"Bureaucrat.hpp"

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
        const int getToSign() const;
        const int getToExecute() const;

        void beSigned(const Bureaucrat& obj);

        class gradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too high!";
                }
        };

        class gradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too low!";
                }
        };
        
};

std::ostream& operator<<(std::ostream &out,Form& obj);

#endif