#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    if (this->_hitPoints == 10)
        this->_hitPoints = 100;
    this->_energyPoints = 50;
    if (this->_attackDamage == 0)
        this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    if (this->_hitPoints == 10)
        this->_hitPoints = 100;
    this->_energyPoints = 50;
    if (this->_attackDamage == 0)
        this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        this->_name = other.getName();
        this->_attackDamage = other.getAttackDamage();
        this->_energyPoints = other.getEnergyPoint();
        this->_hitPoints = other.getHitPoint();
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->_name << " cannot attack with 0 energy point or 0 hit point" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name << " is in gate keeper mode" << std::endl;
}