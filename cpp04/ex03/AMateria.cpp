#include "AMateria.hpp"

AMateria::AMateria(void)
{
    this->_type = "defaultMateria";
    //std::cout << "AMateria default constructor called" << std::endl
}

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
    //std::cout << "AMateria 1 param constructor called" << std::endl
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
    //std::cout << "AMateria copy constructor called" << std::endl
}

AMateria& AMateria::operator=(const AMateria& other)
{
    
    if(this != &other)
        this->_type = other.getType();
    return (*this);
}

AMateria::~AMateria(void)
{
    //std::cout << "AMateria destructor called" << std::endl
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << this->_type << " is used to " << target.getName() << std::endl;
    return ;
}

