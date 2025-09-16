#ifndef SHRUBERRY_CREATION_FORM_HPP
#define SHRUBERRY_CREATION_FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShruberryCreationForm: public AForm
{
    public:
        ShruberryCreationForm(std::string target);
        ShruberryCreationForm(const ShruberryCreationForm& other);
        ~ShruberryCreationForm(void);

        ShruberryCreationForm& operator=(const ShruberryCreationForm& other);

        std::string getTarget(void) const;

        void    execute(Bureaucrat const & executor) const; //override 

    private:
        ShruberryCreationForm(void);
        std::string _target;
};

#endif