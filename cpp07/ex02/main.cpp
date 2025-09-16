#include <iostream>
#include <stdexcept>
#include <string>
#include "Array.hpp"

int main(void)
{
    std::cout << "--------------default-----------------" << std::endl;
    Array<int> empty = Array<int>();

    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

    std::cout << "--------------int-----------------" << std::endl;
    Array<int> a = Array<int>(10);

    for (int i = 0; i < 10; i++)
        std::cout << a[i] << std::endl;

    std::cout << "--------------double-----------------" << std::endl;
    Array<double> b = Array<double>(10);

    for (int i = 0; i < 10; i++)
            std::cout << b[i] << std::endl;

    std::cout << "--------------string and copy-----------------" << std::endl;
    Array<std::string> *c = new Array<std::string>(10);
    Array<std::string> copy = Array<std::string>(5);

    std::cout << "The size of c is " << c->size() << std::endl
              << "The size of copy is " << copy.size() << std::endl;

    for (int i = 0; i < 10; i++)
    {
        if ((*c)[i] == "")
            std::cout << "(Empty string)" << std::endl;
    }

    std::cout << "++copy constructor deep copy++" << std::endl;
    copy = *c;

    std::cout << "The size of c is " << c->size() << std::endl;
    delete c;  //delete the original to test the deep copy

    for (int i = 0; i < 10; i++)
    {
        if (copy[i] == "")
            std::cout << "(Empty string)" << std::endl;
    }

    std::cout << "The size of copy is " << copy.size() << std::endl;

    std::cout << "--------------out of range-----------------" << std::endl;
    Array<std::string> d = Array<std::string>(10);

    try
    {
        if (d[11] == "")
            std::cout << "(Empty string)" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        if (d[-1] == "")
            std::cout << "(Empty string)" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

    return (0);
}