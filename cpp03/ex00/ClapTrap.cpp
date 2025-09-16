#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("defaultClap")
{
    std::cout << "ClapTrap " << this->_name << " default constructor called" << std::endl;

    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;

    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other.getName();
        this->_hitPoints = other.getHitPoint();
        this->_energyPoints = other.getEnergyPoint();
        this->_attackDamage = other.getAttackDamage();
    }
    return (*this);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

unsigned int ClapTrap::getHitPoint(void) const
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoint(void) const
{
    return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name << " cannot attack with 0 energy point or 0 hit point" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        if (this->_hitPoints >= amount)
            this->_hitPoints -= amount;
        else
            this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " takes damage " << amount << " points of damage! He has "
                  << this->_hitPoints << " hit point and " << this->_energyPoints << " energy point left." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name << " cannot take damage with 0 energy point or 0 hit point" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_energyPoints--;
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " is repaired " << amount << " points of hit point! He has "
                  << this->_hitPoints << " hit point and " << this->_energyPoints << " energy point left." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name << " cannot repair himself with 0 energy point or 0 hit point" << std::endl;
}