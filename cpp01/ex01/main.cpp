#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int num_fam = 9;
    Zombie *zombieFamily = zombieHorde(num_fam, "Little zombie");

    for (int i = 0; i < num_fam; i++)
        zombieFamily[i].announce();
    
    delete[] zombieFamily;

    std::cout << std::endl;
    
    int num_com = 5;
    Zombie *zombieCompany = zombieHorde(num_com, "Boss zombie");

    for (int i = 0; i < num_com; i++)
        zombieCompany[i].announce();
    
    delete[] zombieCompany;

    return (0);
}