#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(void): AForm("ShruberryCreationForm", 145, 137)
{
    // default constructor will never be used, because it's private
}

ShruberryCreationForm::ShruberryCreationForm(const std::string target): AForm("ShruberryCreationForm", 145, 137)
{
    this->_target = target;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& other): AForm("ShruberryCreationForm", 145, 137)
{
    *this = other;
}

ShruberryCreationForm::~ShruberryCreationForm(void)
{

}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm& other)
{
    if (this != &other)
    {
        this->_target = other.getTarget();
        setIsSigned(other.getIsSigned());
    }
    return (*this);
}

std::string             ShruberryCreationForm::getTarget(void) const
{
    return (this->_target);
}

void                    ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();

    std::string outfileName = this->_target + "_shrubbery";

    std::ofstream   outputFile(outfileName.data());

    if (!outputFile.good())
    {
        std::cerr << RED << "Error: cannot open " << outfileName << COLOR_END << std::endl;
    }
    outputFile << 
    "                ,@@@@@@@,           \n"
    "    ,,,.   ,@@@@@@ @@,  .oo8888o.   \n"
    "    ,&&%&&%,@@@@@/@@@@@@,8888 88/8o \n"
    ",%& %&&%&&%,@@@ @@@/@@@88 88888/888 \n"
    "%&&%&%&/%&&%@@ @@/ /@@@88888 888888 \n"
    "%&&%/ %& %&&@@  V /@@  `88 8 `/888  \n"
    "`&%  ` /%&     |.|         | |888   \n"
    "    |o|        | |         | |      \n"
    "    |.|        | |         | |      \n"
    " \\/ ._//_/__/  ,/_//__\\/.  /_//__/\n";

    if (!outputFile.good())
    {
        std::cerr << RED << "Error: cannot write " << outfileName << COLOR_END << std::endl;
    }

    outputFile.close();
}