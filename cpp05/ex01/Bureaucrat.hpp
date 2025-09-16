#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

# ifndef COLOR
# define COLOR

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

# endif

class   Form;

class   Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat(void);

        class   GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what(void) const  throw();
        };

        class   GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what(void) const  throw();
        };

        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName(void) const;
        int         getGrade(void) const;

        void        incrementGrade(void);
        void        decrementGrade(void);
        void        signForm(Form& f);

    private:
        const std::string _name;
        int   _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif