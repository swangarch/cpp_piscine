#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
    std::cout << this->_type << " default constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal("Cat")
{
    std::cout << this->_type << " copy constructor called" << std::endl;
    this->_brain = new Brain();
    *this = other;
}

Cat::~Cat(void)
{
    delete (this->_brain);
    std::cout << this->_type << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->_type = other.getType();
        *(this->_brain) = *(other.getBrain());
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->_type << ": Miao~" << std::endl;
}

void    Cat::setBrainIdeas(std::string idea)
{
    this->_brain->setIdeas(idea);
}

void    Cat::showBrainIdeas(void) const
{
    this->_brain->printIdeas();
}

Brain* Cat::getBrain(void) const
{
    return (this->_brain);
}