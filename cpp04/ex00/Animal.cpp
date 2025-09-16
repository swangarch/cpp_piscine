#include "Animal.hpp"

Animal::Animal(void) : _type("defaultAnimal")
{
    std::cout << "Animal " << this->_type << " default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal " << this->_type << " 1 param constructor called" << std::endl;
}

Animal::Animal(const Animal& other): _type(other.getType())
{
    std::cout << "Animal " << this->_type << " copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal " << this->_type << " sound!" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}
