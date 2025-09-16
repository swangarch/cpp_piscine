#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        std::string getTarget(void) const;

        void    execute(Bureaucrat const & executor) const; //override 

    private:
        PresidentialPardonForm(void);
        std::string _target;
};

#endif