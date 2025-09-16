#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

# ifndef COLORS
# define COLORS

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

# endif

class   MateriaSource: public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& other);
        ~MateriaSource(void);

        MateriaSource& operator=(const MateriaSource& other);

        AMateria* const*      getInventory(void) const;
        void            printSlot(void) const;

        void           learnMateria(AMateria* m);
        AMateria*      createMateria(std::string const & type);

    private:
        AMateria*      _inventory[4];
};

#endif