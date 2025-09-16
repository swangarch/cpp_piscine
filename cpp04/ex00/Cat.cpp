#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << this->_type << " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal("Cat")
{
    *this = other;
    std::cout << this->_type << " copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << this->_type << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->_type << ": Miao~" << std::endl;
}