#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main(void)
{
    Zombie zombie1("Cool zombie");
    zombie1.announce();

    Zombie *zombie2;
    zombie2 = newZombie("Beautiful zombie");
    zombie2->announce();

    randomChump("Smart zombie");
    
    delete zombie2;
    return (0);
}