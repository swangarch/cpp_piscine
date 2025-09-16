#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5)
{
    // default constructor will never be used, because it's private
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm("PresidentialPardonForm", 25, 5)
{
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        this->_target = other.getTarget();
        setIsSigned(other.getIsSigned());
    }
    return (*this);
}

std::string             PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void                    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();

    std::cout << YELLOW << this->_target <<" has been pardoned by Zaphod Beeblebrox." << COLOR_END << std::endl;
}