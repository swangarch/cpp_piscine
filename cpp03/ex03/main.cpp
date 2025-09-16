#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << std::endl << "——————————————————————————TEST Diamond 1 param constructor————————————————————————" << std::endl << std::endl;

    DiamondTrap diamond("DiamondA");
    
    for (int i = 0; i < 6; i++)
        diamond.beRepaired(20);
    
    for (int i = 0; i < 6; i++)
    {
        diamond.attack("Diamond_enemy");
        diamond.takeDamage(50);
    }
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();

    std::cout << std::endl << "——————————————————————————TEST Diamond copy constructor————————————————————————" << std::endl << std::endl;

    DiamondTrap diamondtest("diamondTest");
    DiamondTrap diamond2(diamondtest);
    
    for (int i = 0; i < 6; i++)
        diamond2.beRepaired(20);
    
    for (int i = 0; i < 6; i++)
    {
        diamond2.attack("Diamond2_enemy");
        diamond2.takeDamage(50);
    }
    diamond2.highFivesGuys();
    diamond2.guardGate();
    diamond2.whoAmI();

    std::cout << std::endl << "——————————————————————————TEST Diamond default constructor————————————————————————" << std::endl << std::endl;

    DiamondTrap diamond3;
    
    for (int i = 0; i < 6; i++)
        diamond3.beRepaired(20);
    
    for (int i = 0; i < 6; i++)
    {
        diamond3.attack("Diamond3_enemy");
        diamond3.takeDamage(50);
    }
    diamond3.highFivesGuys();
    diamond3.guardGate();
    diamond3.whoAmI();

    std::cout << std::endl << "——————————————————————————Destructors————————————————————————" << std::endl << std::endl;

    return (0);
}