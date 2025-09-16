#include <iostream>
#include "RPN.hpp"

int     main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: invalid arg number." << std::endl;
        return (1);
    }

    if (std::string(av[1]).empty())
    {
        std::cout << "Error: empty arg." << std::endl;
        return (1);
    }

    Rpn rpn(av[1]);
    return (0);
}