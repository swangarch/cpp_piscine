#include <string>
#include <iostream>
#include "PmergeMe.hpp"

bool    alldigits(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(str[i]))
            return (false);
    
    return (true);
}

int main(int ac, char** av)
{
    std::string input;

    if (ac < 2)
    {
        std::cerr << "Error: wrong argument number." << std::endl;
        return (1);
    }

    for (int i = 1; i < ac; i++)
    {
        if (!alldigits(av[i]))
        {
            std::cerr << "Error: wrong argument." << std::endl;
            return (1);
        }
        if (std::string(av[i]).empty())
        {
            std::cerr << "Error: empty argument." << std::endl;
            return (1);
        }
        if (std::string(av[i]).size() > 12 || std::atol(av[i]) > INT_MAX)
        {
            std::cerr << "Error: wrong number." << std::endl;
            return (1);
        }
        input += av[i];
        if (i != ac - 1)
            input += " ";
    }

    try
    {
        PmergeMe    pm(input);
        pm.show(); 
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}