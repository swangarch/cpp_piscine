#include "BitcoinExchange.hpp"

int     main(int ac, char** av)
{
    if (ac == 1)
    {
        std::cout << RED << "Error: no file provided." << COLOR_END << std::endl;
        return (0);
    }
    else if (ac > 2)
    {
        std::cout << RED << "Error: wrong argument number." << COLOR_END << std::endl;
        return (0);
    }

    BitcoinExchange be(av[1]);

    return (0);
}