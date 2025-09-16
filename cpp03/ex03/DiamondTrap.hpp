#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <iostream>
#include <ClapTrap.hpp>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>

class DiamondTrap : public FragTrap , public ScavTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap(void);
        DiamondTrap& operator=(const DiamondTrap& other);

        void    attack(const std::string& target);
        void    whoAmI(void);

        std::string    getName(void) const;

    private:
        std::string     _name;
};


#endif