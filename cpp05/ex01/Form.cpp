#include "Form.hpp"

Form::Form(void): _name("defaultName"), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
    //std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    this->_isSigned = false;

    if (this->_gradeToSign > 150)
        throw Form::GradeTooLowException();
    else if (this->_gradeToSign < 1)
        throw Form::GradeTooHighException();

    if (this->_gradeToExec > 150)
        throw Form::GradeTooLowException();
    else if (this->_gradeToExec < 1)
        throw Form::GradeTooHighException();

    //std::cout << "Form param constructor called" << std::endl;
}

Form::Form(const Form& other): _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
    *this = other;

    //std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
    //std::cout << "Form destructor called" << std::endl;
}

const Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_isSigned = other.getIsSigned();
    }
    return (*this);
}

std::string     Form::getName(void) const
{
    return (this->_name);
}

bool            Form::getIsSigned(void) const
{
    return (this->_isSigned);
}

int             Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int             Form::getGradeToExec(void) const
{
    return (this->_gradeToExec);
}

void            Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    
    this->_isSigned = true;
}

const char*     Form::GradeTooHighException::what(void) const throw()
{
        return ("[Exception: Form: Grade is too high.]");
}

const char*     Form::GradeTooLowException::what(void) const throw()
{
        return ("[Exception: Form: Grade is too low.]");
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os  << f.getName() << ", form is " << (f.getIsSigned() ? "signed": "not signed")
        << ", need " << f.getGradeToSign() << " grade bureaucrat to sign, "
        << "need " << f.getGradeToExec() << " grade bureaucrat to execute."
        << std::endl;
    return (os);
}

