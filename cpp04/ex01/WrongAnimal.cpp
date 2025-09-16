#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("defaultWrongAnimal")
{
    std::cout << "WrongAnimal " << this->_type << " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal " << this->_type << " 1 param constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other.getType())
{
    std::cout << "WrongAnimal " << this->_type << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal " << this->_type << " destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal " << this->_type << " sound!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}
