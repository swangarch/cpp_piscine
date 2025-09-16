#include <Cure.hpp>

Cure::Cure(void): AMateria()
{
    this->_type = "cure";
    //std::cout << "Cure default constructer called" << std::endl;
}

Cure::Cure(const Cure& other): AMateria()
{
    this->_type = other.getType();
    //std::cout << "Cure copy constructer called" << std::endl;
}

Cure::~Cure(void)
{
    //std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone(void) const
{
    return (new Cure());
}