#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << this->_type << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal("Dog")
{
    *this = other;
    std::cout << this->_type << " copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << this->_type << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << this->_type << ": Wong~" << std::endl;
}