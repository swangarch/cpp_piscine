#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

# ifndef COLORS
# define COLORS

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

# endif

class   Character: public ICharacter
{
    public:
        Character(void);
        Character(std::string name);
        Character(const Character& other);
        ~Character(void);

        Character& operator=(const Character& other);
        
        std::string const& getName(void) const;
        void        setName(const std::string name);
        AMateria* const*  getInventory(void) const;
        AMateria**  copyUnequipped(void) const;
        int         const& getNumUnequipped(void) const;

        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);

        void    append_unequipped(AMateria* m);

        void    printSlot(void) const;

    private:
        std::string _name;
        int         _num_unequipped;
        AMateria*   _inventory[4];
        AMateria**  _unequipped;
};

#endif