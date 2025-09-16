#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    /*Subject check*/
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    std::cout << std::endl;
    
    /*No weapon check*/
    {
        Weapon club = Weapon("crude spiked club");
        HumanB alex("alex");
        alex.attack();
        alex.setWeapon(club);
        alex.attack();
        club.setType("some other type of club");
        alex.attack();
    }
    return 0;
}