#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "——————————————————————————Default constructor TEST————————————————————————" << std::endl << std::endl;

    ScavTrap st0;
    st0.guardGate();

    std::cout << "——————————————————————————1 param constructor TEST2————————————————————————" << std::endl << std::endl;

    ScavTrap st1("Scav1");

    st1.attack("Scav_enemy1");
    st1.beRepaired(5);
    st1.takeDamage(2);
    st1.takeDamage(15);
    st1.takeDamage(100);
    st1.takeDamage(1);
    st1.beRepaired(2);
    st1.attack("Scav_enemy2");
    st1.guardGate();

    std::cout << "——————————————————————————Copy constructor TEST3————————————————————————" << std::endl << std::endl;

    ScavTrap st2("Scav2");
    ScavTrap st3(st2);
    
    for (int i = 0; i < 6; i++)
        st3.beRepaired(20);
    
    for (int i = 0; i < 6; i++)
    {
        st3.attack("Scav_enemy3");
        st3.takeDamage(50);
    }
    st3.guardGate();

    std::cout << "——————————————————————————Destructors————————————————————————" << std::endl << std::endl;

    return (0);
}