#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}   

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other.getIdeas()[i];
    }
    return (*this);
}

const std::string* Brain::getIdeas(void) const
{
    return (&this->_ideas[0]);
}

void    Brain::setIdeas(std::string idea)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = idea;
}

void    Brain::printIdeas(void) const
{
    for (int i = 0; i < 100; i++)
        std::cout << this->_ideas[i] << " ";
    std::cout << std::endl << std::endl;
}