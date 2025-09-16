#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    // std::cout << "——————————————————————————TEST Clap————————————————————————" << std::endl << std::endl;

    // ClapTrap clap("Clap");
    
    // for (int i = 0; i < 6; i++)
    //     clap.beRepaired(20);
    
    // for (int i = 0; i < 6; i++)
    // {
    //     clap.attack("Scav_enemy3");
    //     clap.takeDamage(50);
    // }

    // std::cout << "——————————————————————————TEST Scav————————————————————————" << std::endl << std::endl;

    // ScavTrap scav("Scav");
    
    // for (int i = 0; i < 6; i++)
    //     scav.beRepaired(20);
    
    // for (int i = 0; i < 6; i++)
    // {
    //     scav.attack("Scav_enemy3");
    //     scav.takeDamage(50);
    // }
    // scav.guardGate();

    std::cout << "——————————————————————————TEST Frag 1 param constructor————————————————————————" << std::endl << std::endl;

    FragTrap frag("Frag");
    
    for (int i = 0; i < 6; i++)
        frag.beRepaired(20);
    
    for (int i = 0; i < 6; i++)
    {
        frag.attack("Scav_enemy3");
        frag.takeDamage(50);
    }
    frag.highFivesGuys();

    std::cout << "——————————————————————————TEST Frag copy constructor————————————————————————" << std::endl << std::endl;

    FragTrap frag1("frag2");
    FragTrap frag2(frag1);
    
    for (int i = 0; i < 6; i++)
        frag2.beRepaired(20);
    
    for (int i = 0; i < 6; i++)
    {
        frag2.attack("Scav_enemy3");
        frag2.takeDamage(50);
    }
    frag2.highFivesGuys();

    std::cout << "——————————————————————————TEST Frag default constructor————————————————————————" << std::endl << std::endl;

    FragTrap frag3;
    
    for (int i = 0; i < 6; i++)
        frag3.beRepaired(20);
    
    for (int i = 0; i < 6; i++)
    {
        frag3.attack("Scav_enemy3");
        frag3.takeDamage(50);
    }
    frag3.highFivesGuys();

    std::cout << "——————————————————————————Destructors————————————————————————" << std::endl << std::endl;

    return (0);
}