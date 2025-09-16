#include "Character.hpp"

Character::Character(void)
{
    this->_name = "defaultCharacter";

    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;

    this->_num_unequipped = 2;

    this->_unequipped = new AMateria*[this->_num_unequipped];
    for (int i = 0; i < this->_num_unequipped; i++)
        this->_unequipped[i] = NULL;

    //std::cout << "Character " << this->_name << " default constructor called" << std::endl;
}

Character::Character(std::string name)
{
    this->_name = name;

    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;

    this->_num_unequipped = 2;

    this->_unequipped = new AMateria*[this->_num_unequipped];
    for (int i = 0; i < this->_num_unequipped; i++)
        this->_unequipped[i] = NULL;

    //std::cout << "Character " << this->_name << " 1 param constructor called" << std::endl;
}

Character::Character(const Character& other)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;

    this->_num_unequipped = 2;

    this->_unequipped = new AMateria*[this->_num_unequipped];
    for (int i = 0; i < this->_num_unequipped; i++)
        this->_unequipped[i] = NULL;

    *this = other;
    //std::cout << "Character " << this->_name << " copy constructor called" << std::endl;
}

Character::~Character(void)
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

    for (int i = 0; i < this->_num_unequipped; i++)
    {
        if (this->_unequipped[i] != NULL)
        {
            delete (this->_unequipped[i]);
            this->_unequipped[i] = NULL;
        }
    }
    delete [] this->_unequipped;

    //std::cout << "Character " << this->_name << " destructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other.getName();
        this->_num_unequipped = other.getNumUnequipped();

        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i] != NULL)
            {
                delete (this->_inventory[i]);
                this->_inventory[i] = NULL;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (other.getInventory()[i])
                this->_inventory[i] = other.getInventory()[i]->clone();
            else
                this->_inventory[i] = NULL;
        }

        for (int i = 0; i < this->_num_unequipped; i++)
        {
            if (this->_unequipped[i] != NULL)
            {
                delete (this->_unequipped[i]);
                this->_unequipped[i] = NULL;
            }
        }
        delete [] this->_unequipped;

        this->_unequipped = other.copyUnequipped();
    }
    return (*this);
}

std::string const& Character::getName(void) const
{
    return (this->_name);
}

void        Character::setName(const std::string name)
{
    this->_name = name;
}

AMateria* const*  Character::getInventory(void) const //deep copy
{
    return (this->_inventory);
}

AMateria**  Character::copyUnequipped(void) const //deep copy
{
    AMateria** tmp = new AMateria*[this->_num_unequipped];

    for (int i = 0; i < this->_num_unequipped; i++)
    {
        if (this->_unequipped[i])
            tmp[i] = this->_unequipped[i]->clone();
        else
            tmp[i] = NULL;
    }
    return (tmp);
}

int         const& Character::getNumUnequipped(void) const
{
    return (this->_num_unequipped);
}

void    Character::equip(AMateria* m)
{
    if (m == NULL)
        return ;
    
    for (int i = 0; i < 4; i++)
    {
        if (m == this->_inventory[i])
        {
            std::cout << "Error: Cannot equipe already equipped materia" << std::endl;
            return ;
        }
    }
    for (int i = 0; i < this->_num_unequipped; i++)
    {
        if (m == this->_unequipped[i])
        {
            std::cout << "Error: Cannot equipe already unequipped materia" << std::endl;
            return ;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL && (m->getType() == "ice" || m->getType() == "cure"))
        {
            this->_inventory[i] = m;
            return ;
        }
    }
}

void    Character::unequip(int idx)
{
    if (idx >= 4)
        return ;

    for (int i = 0; i < 4; i++)
    {
        if (i == idx)
        {
            this->append_unequipped(this->_inventory[i]);
            this->_inventory[i] = NULL;
            return ;
        }
    }
}

void    Character::append_unequipped(AMateria* m)
{
    AMateria** tmp_container;
    int        old_num;

    while (1)
    {
        for (int i = 0; i < this->_num_unequipped; i++)
        {
            if (this->_unequipped[i] == NULL)
            {
                this->_unequipped[i] = m;
                return ;
            }
            else if (this->_unequipped[i] != NULL && i >= this->_num_unequipped - 1) //container full need to make a bigger one
            {
                old_num = this->_num_unequipped;
                this->_num_unequipped *= 1.5;
                tmp_container = new AMateria*[this->_num_unequipped];
                for (int i = 0; i < this->_num_unequipped; i++)
                    tmp_container[i] = NULL;

                for (int i = 0; i < old_num; i++)
                    tmp_container[i] = this->_unequipped[i];

                delete [] this->_unequipped;
                this->_unequipped = tmp_container;
            }
        }
    }
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= 4)
    {
        std::cout << "Error: Max index is 3" << std::endl;
        return;
    }
    if (this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
    }
}

void           Character::printSlot(void) const  //for debug
{
    std::cout << RED << "+++++++++++++++++++CharacterSLOT+++++++++++++++++++" << std::endl;
    std::cout << "Name: " << this->_name << std::endl << std::endl;

    std::cout << "Inventory:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            std::cout << i << " : " << this->_inventory[i]->getType() << " addresse: " << this->_inventory[i] << std::endl;
        else
            std::cout << i << " : NULL" << std::endl;
    }

    std::cout << std::endl << "Materia unequipped:" << std::endl;
    for (int i = 0; i < this->_num_unequipped; i++)
    {
        if (this->_unequipped[i])
            std::cout << i << " : " << this->_unequipped[i]->getType() << " addresse: " << this->_unequipped[i] << std::endl;
        else
            std::cout << i << " : NULL" << std::endl;
    }
    std::cout << "-------------------CharacterSLOT-------------------" << COLOR_END << std::endl;
}


