#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form
{
    public:
        Form(void);
        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        Form(const Form& other);
        ~Form(void);

        const Form& operator=(const Form &other);

        void    beSigned(const Bureaucrat& b);

        std::string getName(void) const;
        bool        getIsSigned(void) const;
        int         getGradeToSign(void) const;
        int         getGradeToExec(void) const;

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

    private:
        const std::string   _name;
        bool                _isSigned;
        const   int         _gradeToSign;
        const   int         _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif