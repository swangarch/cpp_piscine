 #include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("defaultBureaucrat")
{
    this->_grade = 1;
    //std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
    //std::cout << "Bureaucrat params constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName())
{
    *this = other;
    //std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    //std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other.getGrade();
    }
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void        Bureaucrat::incrementGrade(void)
{
    int tmp = this->_grade - 1;
    
    if (tmp > 150)
        throw Bureaucrat::GradeTooLowException();
    if (tmp < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = tmp;
}

void        Bureaucrat::decrementGrade(void)
{
    int tmp = this->_grade + 1;
    
    if (tmp > 150)
        throw Bureaucrat::GradeTooLowException();
    if (tmp < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = tmp;
}

void        Bureaucrat::signForm(Form& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << YELLOW << this->_name << " signed " << f.getName() << COLOR_END << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << "." << COLOR_END << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
        return ("[Exception: Bureaucrat: Grade is too high.]");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
        return ("[Exception: Bureaucrat: Grade is too low.]");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (os);
}
