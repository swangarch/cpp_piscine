#include <iostream>
#include "Bureaucrat.hpp"

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

int main(void)
{
    std::cout << "___________________Constructor test____________________" << std::endl << std::endl;
    std::cout << "TEST a:" << std::endl;
    try
    {
        Bureaucrat a("a", -1);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }

    std::cout << "TEST b:" << std::endl;
    try
    {
        Bureaucrat b("b", 600);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }

    std::cout << std::endl << "_______________Increment/Decrement test________________" << std::endl << std::endl;

    std::cout << "TEST c:" << std::endl;
    Bureaucrat c("c", 130);
    try
    {
        for (int i = 0; i < 22; i++)
        {
            c.decrementGrade();
            std::cout << c;
        }
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }
    std::cout << std::endl;

    std::cout << "TEST d:" << std::endl;
    Bureaucrat d("d", 10);
    try
    {
        for (int i = 0; i < 22; i++)
        {
            d.incrementGrade();
            std::cout << d;
        }
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }
}