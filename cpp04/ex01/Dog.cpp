#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << this->_type << " default constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal("Dog")
{
    std::cout << this->_type << " copy constructor called" << std::endl;
    this->_brain = new Brain();
    *this = other;
}

Dog::~Dog(void)
{
    delete (this->_brain);
    std::cout << this->_type << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->_type = other.getType();
        *(this->_brain) = *(other.getBrain()); //copy brain
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << this->_type << ": Wong~" << std::endl;
}

void    Dog::setBrainIdeas(std::string idea)
{
    this->_brain->setIdeas(idea);
}

void    Dog::showBrainIdeas(void) const
{
    this->_brain->printIdeas();
}

Brain* Dog::getBrain(void) const
{
    return (this->_brain);
}