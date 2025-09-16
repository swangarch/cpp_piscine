#include <Ice.hpp>

Ice::Ice(void): AMateria()
{
    this->_type = "ice";
    //std::cout << "Ice default constructer called" << std::endl;
}

Ice::Ice(const Ice& other): AMateria()
{
    this->_type = other.getType();
    //std::cout << "Ice copy constructer called" << std::endl;
}

Ice::~Ice(void)
{
    //std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

void Ice::use(ICharacter& target)
{
    std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone(void) const
{
    return (new Ice());
}