#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;

    //std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;

    *this = other;
    //std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    #ifdef DEBUG               //show content in the slot for debug
        this->printSlot();
    #endif

    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] != NULL)
        {
            delete (this->_inventory[i]);
            this->_inventory[i] = NULL;
        }
    }
    //std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)  ////need deep copy
{    
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete(this->_inventory[i]);
            this->_inventory[i] = NULL;
        }

        for (int i = 0; i < 4; i++)
        {
            if (other.getInventory()[i])
            {
                this->_inventory[i] = other.getInventory()[i]->clone();
            }
        }
    }
    return (*this);
}

AMateria* const*    MateriaSource::getInventory(void) const
{
    return (this->_inventory);
}

void           MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << "Error: no Materia"  << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            return ;
        }
    }
}

void           MateriaSource::printSlot(void) const  //for debug
{
    std::cout << YELLOW << "+++++++++++++++++++MateriaSouceSLOT+++++++++++++++++++" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            std::cout << i << " : " << this->_inventory[i]->getType() << " addresse: " << this->_inventory[i] << std::endl;
        else
            std::cout << i << " : NULL" << std::endl;
    }
    std::cout << "-------------------MateriaSouceSLOT-------------------" << COLOR_END << std::endl;
}

AMateria*      MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
            return (this->_inventory[i]->clone());
    }
    return (NULL);
}