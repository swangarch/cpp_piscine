#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

# ifndef COLOR
# define COLOR

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

# endif

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        ~Intern(void);

        Intern& operator=(const Intern& other);
        
        AForm* makeForm(std::string name, std::string target);
};

#endif