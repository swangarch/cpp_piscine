#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB(void)
{
    ;
}

void HumanB::attack(void) const
{
    if (this->_weapon)
        std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " cannot attack without weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}