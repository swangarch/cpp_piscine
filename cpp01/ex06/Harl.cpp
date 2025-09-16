#include "Harl.hpp"

Harl::Harl(void)
{
    ;
}

Harl::~Harl(void)
{
    ;
}

void Harl::debug(void) const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) const
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) const
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) const
{
    std::string complain_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*f[4])(void) const;
    f[0] = &Harl::debug;
    f[1] = &Harl::info;
    f[2] = &Harl::warning;
    f[3] = &Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if (complain_level[i] == level)
            (this->*f[i])();
    }
}

