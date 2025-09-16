#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("defaultDiamond_clap_name"), FragTrap(), ScavTrap()
{
    this->_name = "defaultDiamond";
    std::cout << "DiamondTrap " << this->_name << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
    this->_name = name;
    std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
        this->_name = other.getName();
    return (*this);
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap " << this->_name << "'s ClapTrap name is " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName(void) const
{
    return (this->_name);
}