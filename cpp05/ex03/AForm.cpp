#include "AForm.hpp"

AForm::AForm(void): _name("defaultName"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
    //std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    this->_isSigned = false;

    if (this->_gradeToSign > 150)
        throw AForm::GradeTooLowException();
    else if (this->_gradeToSign < 1)
        throw AForm::GradeTooHighException();

    if (this->_gradeToExec > 150)
        throw AForm::GradeTooLowException();
    else if (this->_gradeToExec < 1)
        throw AForm::GradeTooHighException();

    //std::cout << "Form param constructor called" << std::endl;
}

AForm::AForm(const AForm& other): _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
    *this = other;

    //std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
    //std::cout << "Form destructor called" << std::endl;
}

const AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_isSigned = other.getIsSigned();
    }
    return (*this);
}

std::string     AForm::getName(void) const
{
    return (this->_name);
}

bool            AForm::getIsSigned(void) const
{
    return (this->_isSigned);
}

int             AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int             AForm::getGradeToExec(void) const
{
    return (this->_gradeToExec);
}

void        AForm::setIsSigned(const bool isSigned)
{
    this->_isSigned = isSigned;
}

void            AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    
    this->_isSigned = true;
}

const char*     AForm::GradeTooHighException::what(void) const throw()
{
        return ("[Exception: Form: Grade is too high.]");
}

const char*     AForm::GradeTooLowException::what(void) const throw()
{
        return ("[Exception: Form: Grade is too low.]");
}

const char*     AForm::FormNotSignedException::what(void) const throw()
{
        return ("[Exception: Form: Form has not been signed.]");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os  << f.getName() << ", form is " << (f.getIsSigned() ? "signed": "not signed")
        << ", need " << f.getGradeToSign() << " grade bureaucrat to sign. "
        << " need " << f.getGradeToExec() << " grade bureaucrat to execute. "
        << std::endl;
    return (os);
}

