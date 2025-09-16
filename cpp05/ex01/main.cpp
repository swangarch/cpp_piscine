#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "___________________Constructor test____________________" << std::endl << std::endl;
    std::cout << "TEST a:" << std::endl;
    try
    {
        Form fa = Form("fa", 0, 2);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }

    std::cout << "TEST b:" << std::endl;
    try
    {
        Form fb = Form("fb", 2, 151);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }

    std::cout << std::endl << "_______________sign test________________" << std::endl << std::endl;

    std::cout << "..............................." << std::endl;
    Bureaucrat ba = Bureaucrat("ba", 14);  //cannot sign
    std::cout << ba;
    Form fa = Form("fa", 13, 45);
    ba.signForm(fa);
    std::cout << fa << std::endl;

    Form fa2 = Form("fa2", 13, 45);
    try
    {
        fa2.beSigned(ba);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }
    std::cout << fa2 << std::endl;
    std::cout << "..............................." << std::endl;

    Bureaucrat bb = Bureaucrat("bb", 12); //can sign
    std::cout << bb;
    Form fb = Form("fb", 12, 45);
    bb.signForm(fb);
    std::cout << fb << std::endl;

    Form fb2 = Form("fb2", 12, 45);
    try
    {
        fb2.beSigned(bb);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }
    std::cout << fb2 << std::endl;
    std::cout << "..............................." << std::endl;

    Bureaucrat bc = Bureaucrat("bc", 149); //can sign
    std::cout << bc;
    Form fc = Form("fc", 150, 45);
    bc.signForm(fc);
    std::cout << fc << std::endl;

    Form fc2 = Form("fc2", 150, 45);
    try
    {
        fc2.beSigned(bc);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }
    std::cout << fc2 << std::endl;
    std::cout << "..............................." << std::endl;

    Bureaucrat bd = Bureaucrat("bd", 111); //cannot sign
    std::cout << bd;
    Form fd = Form("fd", 110, 45);
    bd.signForm(fd);
    std::cout << fd << std::endl;

    Form fd2 = Form("fd2", 110, 45);
    try
    {
        fd2.beSigned(bd);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }
    std::cout << fd2 << std::endl;
    std::cout << "..............................." << std::endl;

    Bureaucrat be = Bureaucrat("be", 1); //can sign
    std::cout << be;
    Form fe = Form("fe", 12, 45);
    be.signForm(fe);
    std::cout << fe << std::endl;

    Form fe2 = Form("fe2", 12, 45);
    try
    {
        fe2.beSigned(be);
    }
    catch(std::exception& e)
    {
        std::cout << RED << e.what() << COLOR_END << std::endl;
    }
    std::cout << fe2 << std::endl;
    std::cout << "..............................." << std::endl;
}