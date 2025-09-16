#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        std::string getTarget(void) const;

        void    execute(Bureaucrat const & executor) const; //override 

    private:
        RobotomyRequestForm(void);
        std::string _target;
};

#endif