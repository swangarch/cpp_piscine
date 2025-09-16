#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    // std::cout << "____________________ShruberryCreationForm___________________________"  << std::endl;
    // AForm *ppf1 = new ShruberryCreationForm("Tom");

    // Bureaucrat b1a = Bureaucrat("b1a", 25);
    // Bureaucrat b1b = Bureaucrat("b1b", 1);

    // b1a.signForm(*ppf1);
    // ppf1->execute(b1b);
    // delete (ppf1);

    // std::cout << ".............."  << std::endl;
    // AForm *ppf2 = new ShruberryCreationForm("Marc");

    // Bureaucrat b2a = Bureaucrat("b2a", 25);
    // Bureaucrat b2b = Bureaucrat("b2b", 1);

    // b2a.signForm(*ppf2);
    // b2b.executeForm(*ppf2);
    // delete (ppf2);

    // std::cout << ".............."  << std::endl;
    // AForm *ppf3 = new ShruberryCreationForm("Marc");

    // Bureaucrat b3a = Bureaucrat("b3a", 25);
    // Bureaucrat b3b = Bureaucrat("b3b", 6);

    // b3b.executeForm(*ppf3);
    // b3a.signForm(*ppf3);
    // b3b.executeForm(*ppf3);
    // try
    // {   
    //     ppf3->execute(b3b);
    // }
    // catch(std::exception& e)
    // {
    //     std::cout << RED << e.what() << COLOR_END << std::endl;
    // }

    // delete (ppf3);
    // std::cout << "____________________ShruberryCreationForm___________________________"  << std::endl << std::endl;



    // std::cout << "____________________RobotomyRequestForm___________________________"  << std::endl;
    // AForm *ppf4 = new RobotomyRequestForm("Tom");

    // Bureaucrat b4a = Bureaucrat("b4a", 25);
    // Bureaucrat b4b = Bureaucrat("b4b", 1);

    // b4a.signForm(*ppf4);
    // ppf4->execute(b4b);
    // delete (ppf4);

    // std::cout << ".............."  << std::endl;
    // AForm *ppf5 = new RobotomyRequestForm("Marc");

    // Bureaucrat b5a = Bureaucrat("b5a", 25);
    // Bureaucrat b5b = Bureaucrat("b5b", 1);

    // b5a.signForm(*ppf5);
    // b5b.executeForm(*ppf5);
    // delete (ppf5);

    // std::cout << ".............."  << std::endl;
    // AForm *ppf6 = new RobotomyRequestForm("Marc");

    // Bureaucrat b6a = Bureaucrat("b6a", 25);
    // Bureaucrat b6b = Bureaucrat("b6b", 6);

    // b6b.executeForm(*ppf6);
    // b6a.signForm(*ppf6);
    // b6b.executeForm(*ppf6);
    // try
    // {   
    //     ppf6->execute(b3b);
    // }
    // catch(std::exception& e)
    // {
    //     std::cout << RED << e.what() << COLOR_END << std::endl;
    // }

    // delete (ppf6);
    // std::cout << "____________________RobotomyRequestForm___________________________"  << std::endl << std::endl;



    // std::cout << "____________________PresidentialPardonForm___________________________"  << std::endl;
    // AForm *ppf7 = new PresidentialPardonForm("Tom");

    // Bureaucrat b7a = Bureaucrat("b7a", 25);
    // Bureaucrat b7b = Bureaucrat("b7b", 1);

    // b7a.signForm(*ppf7);
    // ppf7->execute(b7b);
    // delete (ppf7);

    // std::cout << ".............."  << std::endl;
    // AForm *ppf8 = new PresidentialPardonForm("Marc");

    // Bureaucrat b8a = Bureaucrat("b8a", 25);
    // Bureaucrat b8b = Bureaucrat("b8b", 1);

    // b8a.signForm(*ppf8);
    // b8b.executeForm(*ppf8);
    // delete (ppf8);

    // std::cout << ".............."  << std::endl;
    // AForm *ppf9 = new PresidentialPardonForm("Marc");

    // Bureaucrat b9a = Bureaucrat("b9a", 25);
    // Bureaucrat b9b = Bureaucrat("b9b", 6);

    // b9b.executeForm(*ppf9);
    // b9a.signForm(*ppf9);
    // b9b.executeForm(*ppf9);
    // try
    // {   
    //     ppf9->execute(b9b);
    // }
    // catch(std::exception& e)
    // {
    //     std::cout << RED << e.what() << COLOR_END << std::endl;
    // }

    // delete (ppf9);
    // std::cout << "____________________PresidentialPardonForm___________________________"  << std::endl << std::endl;

    Intern  someRandomIntern;
    AForm*   rrf1;
    AForm*   rrf2;
    AForm*   rrf3;
    AForm*   rrf4;

    rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf2 = someRandomIntern.makeForm("shrubbery creation", "Tom");
    rrf3 = someRandomIntern.makeForm("presidential pardon", "Marc");
    rrf4 = someRandomIntern.makeForm("random form", "Paul");

    delete  rrf1;
    delete  rrf2; 
    delete  rrf3; 
    delete  rrf4;
}