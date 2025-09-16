#include "Intern.hpp"

Intern::Intern(void)
{

}

Intern::Intern(const Intern& other)
{
    (void)other;
    *this = other;
}

Intern::~Intern(void)
{

}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

static  int getIndex(const std::string name, const std::string* validForms)
{
    for (int i = 0; i < 3; i++)
        if (validForms[i] == name)
            return (i);

    return (-1);
}
        
AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string validForms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};

    int index = getIndex(name, validForms);

    switch (index)
    {   
        case 0:
            std::cout << YELLOW << "Intern creates " << validForms[index] << " form." << std::endl; 
            return (new RobotomyRequestForm(target));
            break ;

        case 1:
            std::cout << YELLOW << "Intern creates " << validForms[index] << " form." << std::endl; 
            return (new ShruberryCreationForm(target));
            break ;

        case 2:
            std::cout << YELLOW << "Intern creates " << validForms[index] << " form." << std::endl; 
            return (new PresidentialPardonForm(target));
            break ;
        
        default:
            std::cout << RED << "Error: Form doesn't exist." << COLOR_END << std::endl;
            return (NULL);
            break;
    }
    std::cout << RED << "Error: Form doesn't exist." << COLOR_END << std::endl;
    return (NULL);
}