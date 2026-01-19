#include"ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"
ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm",145,137),target("Default")
{}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("ShrubberyCreationForm",145,137),target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other),target(other.target)
{}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(this->getBool() == false)//form is not signed so we cannot execute it
        throw AForm::NotSignedException();
    if(executor.getGrade() > this->getToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream outfile((this->target + "_shrubbery").c_str());//.c_str() converts a std::string into a C-style string 
    if (!outfile)
    {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }
    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    outfile.close();
}