#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   AForm
{
    public:
        AForm(void);
        AForm(const std::string name, const int gradeToSign, const int gradeToExec);
        AForm(const AForm& other);
        virtual ~AForm(void);

        const AForm& operator=(const AForm &other);

        std::string getName(void) const;
        bool        getIsSigned(void) const;
        int         getGradeToSign(void) const;
        int         getGradeToExec(void) const;

        void        setIsSigned(const bool isSigned);

        void    beSigned(const Bureaucrat& b);
        virtual void    execute(Bureaucrat const & executor) const = 0 ;

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

        class   FormNotSignedException: public std::exception
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

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif