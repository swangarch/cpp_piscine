#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "----------------Default constructor----------------------" << std::endl << std::endl;

    ClapTrap cp1;
    cp1.attack("little boss");
    cp1.beRepaired(5);
    cp1.takeDamage(2);
    cp1.takeDamage(15);
    cp1.beRepaired(2);
    cp1.attack("medium boss");
    std::cout << std::endl;

    std::cout << "--------------one param constructor--------------------" << std::endl << std::endl;

    ClapTrap cp2("happy boss");
    for (int i = 0; i < 15; i++)
        cp2.beRepaired(2);

    std::cout << std::endl;

    std::cout << "-------------------copy constructor--------------------" << std::endl << std::endl;
    ClapTrap cp3("sad boss");
    ClapTrap cp4(cp3);
    for (int i = 0; i < 15; i++)
        cp4.attack("medium boss");

    std::cout << "----------------------destructor----------------------" << std::endl << std::endl;
    return (0);
}