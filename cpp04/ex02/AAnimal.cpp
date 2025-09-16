#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("defaultAnimal")
{
    std::cout << "Animal " << this->_type << " default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
    std::cout << "Animal " << this->_type << " 1 param constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): _type(other.getType())
{
    std::cout << "Animal " << this->_type << " copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

// ABSTRACT CLASS DON'T IMPLEMENT PURE VIRTUAL FUNCTION
// void    AAnimal::makeSound(void) const   
// {
//     std::cout << "Animal " << this->_type << " sound!" << std::endl;
// }
// ABSTRACT CLASS DON'T IMPLEMENT PURE VIRTUAL FUNCTION

std::string AAnimal::getType(void) const
{
    return (this->_type);
}
