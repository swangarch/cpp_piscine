#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class   Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat(void);

        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName(void) const;
        int         getGrade(void) const;

        void        incrementGrade(void);
        void        decrementGrade(void);

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
        const std::string _name;
        int   _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif