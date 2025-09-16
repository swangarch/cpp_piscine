#include <iostream>
#include <string>
#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    harl.complain("DEBUG");
    return (0);
}