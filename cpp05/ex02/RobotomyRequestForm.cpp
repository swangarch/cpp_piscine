#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45)
{
    // default constructor will never be used, because it's private
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("RobotomyRequestForm", 72, 45)
{
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        this->_target = other.getTarget();
        setIsSigned(other.getIsSigned());
    }
    return (*this);
}

std::string             RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void                    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    
    srand(time(NULL));
    int r = rand();
    if (r % 2)
        std::cout << YELLOW << this->_target <<" has been robotomized successfully. :)" << COLOR_END << std::endl;
    else
        std::cout << RED << this->_target <<" has failed to be robotomized. :(" << COLOR_END << std::endl;

}